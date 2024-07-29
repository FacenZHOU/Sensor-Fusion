# Sensor-Fusion
## Contents
The following topics are covered in course projects:

### Course 1: Lidar
* **Lidar Sensor & Point Clouds** — How Lidar data is represented, how Point Cloud Data (PCD) is generated using simulation software, and how Lidar data can be visualised;
* **Point Cloud Segmentation** — Using Point Cloud Library (PCL) to segment point clouds, and performing planar model fitting using the RANSAC algorithm;
* **Clustering Obstacles** — Using PCL to cluster obstacles, storing point cloud data with a KD-Tree, implementing Euclidean Clustering to identify point clusters, and applying bounding boxes around point clusters;
* **Point Cloud Data (PCD) Workflows** — Working with real-world PCD-file datasets, filtering and processing PCD data, and performing obstacle detection;
* And so much more ... (see 1-Lidar for full list of course topics).
### Course 2: Camera
* **Sensor Fusion & Autonomous Driving** — Understanding the SAE levels of autonomy, comparing typical OEM sensor configurations, and performing sensor modality tradeoff analysis against industry-grade criteria;
* **Camera Technology & Collision Detection** — Reviewing essential camera working principles, performing image manipulation using OpenCV library, and designing a collision detection system based on motion models, Lidar and camera measurement data;
* **Feature Tracking** — Detecting object features in camera images using popular methods, and performing feature matching to track objects over time using binary descriptors;
Camera & Lidar Fusion — Projecting 3D Lidar points into camera sensor coordinate frames, using deep learning models to perform object detection in camera images, creating 3D object representations from the fusion of Lidar and camera data.
### Course 3: Radar
* **Radar Sensor** — Handling real-world radar data, calculating object heading and velocity, and task-specific sensor modality tradeoff analysis;
* **Radar Calibration** — Correcting radar data to account for radial velocity, and filtering noise from real-world radar sensor data;
* **Radar Detection** — Thresholding radar signatures to eliminate false positives, and predicting the location of occluded objects.
### Course 4: Kalman Filters
* **Kalman Filters** — Constructing Kalman filters, merging data from multiple sources, improving object tracking accuracy, and reducing sensor noise;
* **Lidar & Radar Fusion with Kalman Filters** — Building a Kalman filter programme in C++, and handling Lidar and radar data;
* **Extended Kalman Filter (EKF)** — Predicting filtering errors resulting from non-linear motion, adapting Kalman filter programme to handle non-linear motion with Extended Kalman filter (EKF), and defining Jacobian matrices for the EKF;
* **Unscented Kalman Filter (UKF)** — Addressing the limitations of the EKF with highly non-linear motion, and adapting the EKF to accurately track non-linear motion with the Unscented Kalman filter (UKF).
 
