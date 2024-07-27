#include "kdtree.h"

void clusterHelper(int indice, const std::vector<std::vector<float>> points, std::vector<int>& cluster, std::vector<bool>& processed, KdTree* tree, float distanceTol)
{

	const std::vector<float> point = points[indice];
	processed[indice] = true;
	cluster.push_back(indice);
	
	const std::vector<int> nearst = tree->search(point, distanceTol);

	for(const int id : nearst)
	{
		if(!processed[id])
		{
			clusterHelper(id, points, cluster, processed, tree, distanceTol);
		}
		
	}

	std::cout << "erfolgreich" << std::endl;
	
}

std::vector<std::vector<int>> euclideanCluster(const std::vector<std::vector<float>>& points, KdTree* tree, float distanceTol)
{

	// TODO: Fill out this function to return list of indices for each cluster

	std::vector<std::vector<int>> clusters;

	// Status vector to tell us which points have been processed
	std::vector<bool> processed(points.size(), false);

	// Iterate through each point
	for (size_t i = 0; i < points.size(); i++)
	{
		if (processed[i]) {continue;}

		std::vector<int> cluster;
		
		clusterHelper(i, points, cluster, processed, tree, distanceTol);

		clusters.push_back(cluster);
		
		
	}
	 
	std::cout << "####### erfolgreich" << std::endl;
 
	return clusters;

}