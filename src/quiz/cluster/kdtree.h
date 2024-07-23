#ifndef __KDTREE_H__
#define __KDTREE_H__

#include "../../render/render.h"
#include <iostream>


// Structure to represent node of kd tree
struct Node
{
	std::vector<float> point;
	int id;
	Node* left;
	Node* right;

	Node(std::vector<float> arr, int setId)
	:	point(arr), id(setId), left(NULL), right(NULL)
	{}

	~Node()
	{
		delete left;
		delete right;
	}
};

struct KdTree
{
	Node* root;

	KdTree()
	: root(NULL)
	{}

	~KdTree()
	{
		delete root;
	}

	void insert(std::vector<float> point, int id)
	{
		if (root==NULL)
		{
			root = new Node(point,id);
			return;
		}
		
		Node* ptr = root;

		int depth = 0;

		while (ptr != nullptr)
		{
			const int index = depth % point.size();
			const float ref_src = ptr->point[index];
			const float ref_to_comp = point[index];

			if (ref_to_comp < ref_src)
			{
				if (ptr->left == nullptr)
				{
					ptr->left = new Node(point, id);
					break;
				}

				ptr = ptr->left;
			}
			else if (ref_to_comp > ref_src)
			{
				if (ptr->right == nullptr)
				{
					ptr->right = new Node(point, id);
					break;
				}
				ptr = ptr->right;
			}

			depth++;
		}
	}

	/*
	void insert(std::vector<float> point, int id)
	{
		// TODO: Fill in this function to insert a new point into the tree
		// the function should create a new node and place correctly with in the root 
		insertHelper(&root,0,point,id);

	}
	*/

	void searchHelper(std::vector<float>& target, Node* node, int depth, const float& distanceTol, std::vector<int>& ids)
	{
		if (node == nullptr)
		{
			return;
		}
	
		const int index = depth % target.size();
		const float ref_node = node->point[index];
		const float ref_target = target[index];

		bool check = true;
		
		for (size_t i=0; i<target.size(); i++)
		{
			//std::cout << target.size() << std::endl;
			//std::cout << "SearchHelper 001!" << std::endl;
			check &= (std::abs(node->point[i] - target[i]) <= distanceTol);
			//std::cout << check << std::endl;
			//std::cout << std::abs(node->point[i] - target[i]) << std::endl;
		}

		if (check)
		{
			double dist = 0.0;
			//std::cout << "check" << std::endl;
			//std::cout << target.size() << std::endl;
			for (size_t i = 0; i<target.size(); i++)
			{ 
				//std::cout << "SearchHelper 002!" << std::endl;
				dist += (node->point[i] - target[i]) * (node->point[i] - target[i]);
			}

			if (dist <= (distanceTol * distanceTol)) {ids.push_back(node->id);}
		}


		if ((ref_target-distanceTol) < ref_node)
		{
		    //std::cout << "SearchHelper 003!" << std::endl;
			searchHelper(target, node->left, depth+1, distanceTol, ids);
		}
			
		if ((ref_target+distanceTol) > ref_node)
		{
			//std::cout << ref_target+distanceTol << std::endl;
			//std::cout << ref_node << std::endl;
			//std::cout << "SearchHelper 004!" << std::endl;
			searchHelper(target,node->right, depth+1, distanceTol, ids);
		}
	
	}

	// return a list of point ids in the tree that are within distance of target
	std::vector<int> search(std::vector<float> target, float distanceTol)
	{
		std::vector<int> ids;
		searchHelper(target, root, 0, distanceTol, ids);

		return ids;
	}
	

};


#endif

