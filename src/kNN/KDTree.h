/**
 * File: KDTree.h
 * Author: FateLess
 * An interface representing a kd-tree in some numnber of dimensions.
*/

#ifndef KDTREE_INCLUDED
#define KDTREE_INCLUDED

#include "Point.h"
#include "BoundedPQueue.h"
#include <stdexcept>
#include <cmath>
#include <set>

using namespace std;

template <size_t N, typename ElemType>
class KDTree {
public:
	KDTree();
	~KDTree();

	KDTree(const KDTree& rhs);
	KDTree& operator=(const KDTree& rhs);

	size_t dimension() const;

	size_t size() const;
	bool empty() const;

	bool contains(const Point<N>& pt) const;

	void insert(const Point<N>& pt, const ElemType& value);

	ElemType& operator[](const Point<N>& pt);

	ElemType& at(const Point<N>& pt);
	const ElemType& at(const Point<N>& pt) const;

	ElemType KNNValue(const Point<N>& key, size_t k) const;
	
private:

	struct ElemNode {
		Point<N> key;
		size_t level;
		ElemType value;
		ElemNode *lson;
		ElemNode *rson;
	};
	size_t numOfElems;
	ElemNode *root;

	ElemType& findNode(const Point<N>& pt) const;
	void findKNNValue(const Point<N>& key, const BoundedPQueue<ElemNode*>& bpq) const;
	ElemType getMostFrequentValue(const BoundedPQueue<ElemNode*>& bpq) const;
};

template <size_t N, typename ElemType>
KDTree<N, ElemType>::KDTree() {
	
}

template <size_t N, typename ElemType>
KDTree<N, ElemType>::~KDTree() {
	
}

template <size_t N, typename ElemType>
size_t KDTree<N, ElemType>::dimension() const {
	return N;
}

template <size_t N,  typename ElemType>
size_t KDTree<N, ElemType>::size() const {
	return numOfElems;
}

template <size_t N, typename ElemType>
void KDTree<N, ElemType>::empty() const {
	return numOfElems == 0;
}

template <size_t N, typename ElemType>
bool KDTree<N, ElemType>::contains(const Point<N>& pt) const {
	return findNode(pt) != NULL;
}

template <size_t N, typename ElemType>
ElemType& KDTree<N, ElemType>::findNode(const Point<N>& pt) const {
	for (ElemNode *currNode = root, size_t level = 0; currNode != NULL; ++level) {
		size_t keyIndex = level % N;
		if (currNode->key == pt) {
			return currNode->vale;
		}
		if (pt[keyIndex] < currNode->key[keyIndex]) {
			currNode = currNode->lson;
		} else {
			currNode = currNode->rson;
		}
	}
	return NULL;
}

template <size_t N, typename ElemType>
ElemType& KDTree<N, ElemType>::operator[](const Point<N>& pt) {
	return findNode(pt);
}

template <size_t N, typename ElemType>
ElemType KDTree<N, ElemType>::KNNValue(const Point<N>& pt, size_t k) const {
	BoundedPQueue<ElemNode*> bpq(k);

}

template <size_t N, typename ElemType>
void KDTree<N, ElemType>::findKNNValue(const Point<N>& key, const BoundedPQueue<ElemNode*>& bpq) const {
	for (ElemNode* currNode = root, size_t level = 0; currNode != NULL; ++level) {
		size_t keyIndex = level % N;
		bpq.enqueue(currNode->value, Distance(currNode->key, key);

		if (key[keyIndex] < currNode->key[keyIndex]) {
				
		}
	}
}

template <size_t N, typename ElemType>
ElemType KDTree<N, ElemType>::getMostFrequentValue(const BoundedPQueue<ElemNode*>& bpq) const {
	multiset<ElemType> valueCount;

	while (!bpq.empty()) {
		valueCount.insert((bpq.dequeueMin())->value);
	}

	size_t mostFrequentCount = 0;
	ElemType mostFrequentValue = NULL;

	for (typename multiset<ElemType>::iterator it = valueCount.begin(); it != valueCount.end(); ++it) {
		if (valueCount.count(*it) > mostFrequentCount) {
			mostFrequentCount = valueCount.count(*it);
			getMostFrequentValue = *it;
		}
	}

	return mostFrequentValue;
}

#endif //KDTREE_INCLUDED