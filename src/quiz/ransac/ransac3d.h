#ifndef _RANSAC_3D_H_
#define _RANSAC_3D_H_

#include <pcl/common/common.h>
#include <unordered_set>

// Practice writing a templated class
/*
template <typename PointT>
class RANSAC3D {
 public:
  static std::unordered_set<int> Ransac3D(
      typename pcl::PointCloud<PointT>::Ptr cloud,
      const int maxIterations,
      const float distanceTol) {
    std::unordered_set<int> inlier_results;
    srand(time(NULL));

    // TODO: Fill in this function
    std::unordered_set<int> proposed_inliers;

    // Number of points
    const int num_points = cloud->points.size();

    // Repeat for a maximum number of iterations
    for (int i = 0; i < maxIterations; i++) {
      proposed_inliers.clear();
      // Obtain the indices to sample
      std::unordered_set<int> indices_to_sample;
      indices_to_sample.insert(std::rand() % num_points);
      indices_to_sample.insert(std::rand() % num_points);
      indices_to_sample.insert(std::rand() % num_points);

      // If we don't have them all unique, try again
      if (indices_to_sample.size() != 3) {
        i--;
        continue;
      }

      // Obtain the points
      std::unordered_set<int>::iterator it = indices_to_sample.begin();
      const auto& pt1 = cloud->points[*it++];
      const auto& pt2 = cloud->points[*it++];
      const auto& pt3 = cloud->points[*it];

      // Calculate the coefficients for the plane
      // A = (y2 - y1)(z3 - z1) - (z2 - z1)(y3 - y1)
      const double A =
          (pt2.y - pt1.y) * (pt3.z - pt1.z) - (pt2.z - pt1.z) * (pt3.y - pt1.y);
      // B = (z2 - z1)(x3 - x1) - (x2 - x1)(z3 - z1)
      const double B =
          (pt2.z - pt1.z) * (pt3.x - pt1.x) - (pt2.x - pt1.x) * (pt3.z - pt1.z);
      // C = (x2 − x1)(y3 − y1) − (y2 − y1)(x3 − x1)
      const double C =
          (pt2.x - pt1.x) * (pt3.y - pt1.y) - (pt2.y - pt1.y) * (pt3.x - pt1.x);
      // D = -(A*x1 + B*y1 + C*z1)
      const double D = -(A * pt1.x + B * pt1.y + C * pt1.z);

      // Find inliers
      for (int j = 0; j < num_points; j++) {
        const auto& pt = cloud->points[j];
        const double dist = std::abs(A * pt.x + B * pt.y + C * pt.z + D) /
                            std::sqrt(A * A + B * B + C * C);
        if (dist <= distanceTol) { proposed_inliers.insert(j); }
      }

      // Retain the best inliers
      if (proposed_inliers.size() > inlier_results.size()) {
        inlier_results = proposed_inliers;
      }
    }

    return inlier_results;
  };
} */


template <typename PointT>
class RANSAC3D 
{
 public:
  static std::unordered_set<int> Ransac3D(
      typename pcl::PointCloud<PointT>::Ptr cloud,
      const int maxIterations,
      const float distanceTol) 
    {
    std::unordered_set<int> inlier_results;
    srand(time(NULL));
	 
    std::unordered_set<int> tempInliersResult;


    for (size_t i = 0; i < maxIterations; i++)
    {
      //std::unordered_set<int> tempInliersResult;
      /*
      while (tempInliersResult.size() < 3)
      {
        tempInliersResult.insert((rand() % cloud->points.size()));
        
      }
      */
      tempInliersResult.clear();
      std::unordered_set<int> indices_to_sample;
      indices_to_sample.insert(std::rand() % cloud->points.size());
      indices_to_sample.insert(std::rand() % cloud->points.size());
      indices_to_sample.insert(std::rand() % cloud->points.size());

      if (indices_to_sample.size() != 3)
      {
        i--;
        continue;
      }

      auto itr = indices_to_sample.begin();
      const auto& randPoint1 = cloud->points[*itr];
      itr++;
      const auto& randPoint2 = cloud->points[*itr];
      itr++;
      const auto& randPoint3 = cloud->points[*itr];

      const double planeAValue = ((randPoint2.y-randPoint1.y)*(randPoint3.z-randPoint1.z)) - ((randPoint2.z-randPoint1.z)*(randPoint3.y-randPoint1.y));
      const double planeBValue = ((randPoint2.z-randPoint1.z)*(randPoint3.x-randPoint1.x)) - ((randPoint2.x-randPoint1.x)*(randPoint3.z-randPoint1.z));
      const double planeCValue = ((randPoint2.x-randPoint1.x)*(randPoint3.y-randPoint1.y)) - ((randPoint2.y-randPoint1.y)*(randPoint3.x-randPoint1.x));
      const double planeDValue = -((planeAValue*randPoint1.x) + (planeBValue*randPoint1.y) + (planeCValue*randPoint1.z));

      for (size_t i =0; i < cloud->points.size(); i++)
      {
        if(tempInliersResult.count(i) > 0) continue;

        const auto& point = cloud->points[i];
        const double distance = fabs((planeAValue * point.x) + (planeBValue * point.y) + (planeCValue * point.z) + planeDValue) / (sqrt((planeAValue*planeAValue) + (planeBValue*planeBValue) + (planeCValue*planeCValue)));

        if (distance <= distanceTol)
          tempInliersResult.insert(i);
      }

      if (tempInliersResult.size()> inlier_results.size())
        inlier_results = tempInliersResult;
    }

    return inlier_results;
      };

};
#endif