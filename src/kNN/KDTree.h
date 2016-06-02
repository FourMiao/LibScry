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
};

template <size_t N, typename ElemType>
KDTree<N, ElemType>::KDTree() {
	
}

template <size_t N, typename ElemType>
KDTree<N, ElemType>::~KDTree() {
	
}

template <size_t N, typename ElemType>
size_t KDTree<N, ElemType>::dimension() const {
	return 0;
}

#endif //KDTREE_INCLUDED