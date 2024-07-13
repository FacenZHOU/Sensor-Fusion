#ifndef __EUCLIDEAN_CLUSTER_H__
#define __EUCLIDEAN_CLUSTER_H__
#include "kdtree.h"

void clusterHelper(int indice, 
                    const std::vector<std::vector<float>> points, 
                    std::vector<int>& cluster, 
                    std::vector<bool> processed, 
                    KdTree* tree, 
                    float distanceTol);

std::vector<std::vector<int>> euclideanCluster(const std::vector<std::vector<float>>& points, 
                                                KdTree* tree, 
                                                float distanceTol);
#endif