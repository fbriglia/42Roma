#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cstddef>
#include <ctime>
#include <iostream>
#include <utility>

template <typename T, typename P> class PmergeMe {
  private:
    std::string title;
    T sequence;
    P pairs;
    clock_t start, end;

    PmergeMe(const PmergeMe &pmm) { *this = pmm; }
    PmergeMe &operator=(const PmergeMe &pmm) {
        if (this == &pmm)
            return *this;
        title = pmm.title;
        sequence = pmm.sequence;
        pairs = pmm.pairs;
        start = pmm.start;
        return *this;
    }

    void startTimer() { start = std::clock(); }

    void stopTimer() { end = std::clock(); }

    int getJacobNum(int n) {
        if (n == 0)
            return 0;
		    if (n == 1)
		        return 1;
		    return getJacobNum(n - 1) + 2 * getJacobNum(n - 2);
    }

    int bisect(int x) {
        int lo = 0;
        int hi = sequence.size();

        while ( lo < hi ) {
            int mid = ( lo + hi ) / 2;
            if (x < sequence[mid])
                hi = mid;
            else
                lo = mid + 1;
        }
	   return (lo);
    }

  public:
    typedef typename T::iterator iterator;
    typedef typename P::iterator pairs_iterator;

    PmergeMe(const std::string &t) : title(t) {}
    ~PmergeMe() {}

    void push_back(int i) { sequence.push_back(i); }

    void printProcessTime() {
        std::cout << "Time to process a range of " << sequence.size() << " elements with "
                  << title << " is: " << ((end - start) / (double)100) << " us"
                  << std::endl;
    }

    void printSorted() {
        iterator it = sequence.begin();
        for (; it != sequence.end() && it - sequence.begin() < 7; it++)
            std::cout << *it << " ";
        if (it != sequence.end())
            std::cout << "...";
        std::cout << std::endl;
    }

    void makeSortedPairs(size_t size) {
        for (size_t i = 0; i < size - 1; i += 2)
            pairs.push_back(std::make_pair(sequence[i], sequence[i + 1]));

        for (size_t i = 0; i < pairs.size(); i++) {
            if (pairs[i].first < pairs[i].second)
                std::swap(pairs[i].first, pairs[i].second);
        }
    }

    void insertElement(std::pair<int, int> pair, int n) {
        if (n < 0) {
            pairs[0] = pair;
            return;
        }

        int size = pairs.size();
        if (pair.second >= pairs[n].second) {
            if (n == size - 1) {
                pairs.push_back(pair);
            } else {
                pairs[n + 1] = pair;
            }
        } else {
            if (n == size - 1) {
                pairs.push_back(pairs[n]);
            } else {
                pairs[n + 1] = pairs[n];
                insertElement(pair, n - 1);
            }
        }
    }

    void sortPairs(int n) {
        if (n == 0)
            return;
        sortPairs(n - 1);
        insertElement(pairs[n], n - 1);
    }

    bool isSorted() {
        if (sequence.size() < 2) return true;
        for (iterator it = sequence.begin(); it != sequence.end(); it++) {
            iterator next = it + 1;
            if (next != sequence.end() && *it > *next)
                return false;
        }
        return true;
    }

    T createJacobSequence(int size) {
        T jacobseq;
        int index = 3;
        while (getJacobNum(index) < size - 1) {
            jacobseq.push_back(getJacobNum(index));
            index++;
        }
        return jacobseq;
    }

    void createIndexSequence(T &indexseq, int p_size) {
        bool last = false;

        if (p_size == 1)
            return indexseq.push_back(1);

        T jacobseq = createJacobSequence(p_size);

        for (int i = 1; i <= p_size; i++) {
            if (jacobseq.size() != 0 && !last) {
                indexseq.push_back(jacobseq[0]);
                jacobseq.erase(jacobseq.begin());
                last = true;
                continue;
            }
            for (iterator it = indexseq.begin(); it != indexseq.end(); it++) {
                if (*it == i)
                    i++;
            }
            indexseq.push_back(i);
            last = false;
        }
    }

    void insertNumber(int num) {
        int index = bisect(num);
        sequence.insert(sequence.begin() + index, num);
    }

    void makeSortedSequence() {
        T pending;
        T indexseq;

        for (pairs_iterator it = pairs.begin(); it != pairs.end(); it++) {
            sequence.push_back(it->second);
            pending.push_back(it->first);
        }

        createIndexSequence(indexseq, pending.size());

        for (iterator it = indexseq.begin(); it != indexseq.end(); it++) {
            insertNumber(pending[*it - 1]);
        }
    }

    void sort() {
        size_t size = sequence.size();
        int unpaired = -1;
        bool hasUnp = size % 2 == 1;

        startTimer();

        if (isSorted())
            return;

        if (hasUnp)
            unpaired = sequence.back();

        makeSortedPairs(hasUnp ? size - 1 : size);
        sortPairs(pairs.size() - 1);

        // for (pairs_iterator it = pairs.begin(); it != pairs.end(); it++) {
        //     std::cout << it->first << " | " << it->second << std::endl;
        // }

        sequence.clear();
        makeSortedSequence();

        if (hasUnp)
            insertNumber(unpaired);
        stopTimer();
    }
};

#endif
