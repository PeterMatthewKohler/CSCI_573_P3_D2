Compilation and Execution Instructions: \
\
1.) Extract the folder from the tarball into a single location. Ensure that all the files extracted are in the same folder. \
2.) Open a terminal inside the folder that has the extracted files \
3.) type "make" \
4.) The integrated program that fulfills Task 4 is called "integrated.cpp" and will be compiled into an executable called "integrated". \
5.) This program has 4 required arguments. \
\t i.) -r which is a command line flag to signal which model you want \
\t ii.) One of three choices for each of the three representations: "rad", "hjpd", or "hod" \
\t iii.) The desired C parameter value \
\t iv.) The desired gamma parameter value \
Example command line usage: ./integrated -r rad 2 2 \
\
Implementation Information: \
For detected NAN values, the whole frame containing even a single NAN value is deleted. \
RAD: \
The Joints used for the angle and distance calculations are the joints 1, 4, 8, 12, 16, and 20. \
The number of bins used in this implementation is 16. \
The bin width is a determined from calculating the residual of the maximum data value and the minimum data value in the set, and then dividing by the number of bins. \
The histogram is normalized according to the number of frames. \
HJPD: \
The number of bins in each histogram is 15.\
The bin width is a determined from calculating the residual of the maximum data value and the minimum data value in the set, and then dividing by the number of bins. \
The histogram is normalized according to the total number of data points \
\
HOD: \
The number of bins used in the HOD histograms is set to 25 bins. \
The bin width is 14 degrees per bin. \
The histogram uses the distance's magnitude as the real-value count and then is normalized by the total distance traveled in the joint's trajectory. \

SVMF: \
Function to format the data created in deliverable one. Follows the required libSVM format of: \
[label] [index1]:[value1] [index2]:[value2]...

INTEGRATED: \
Makes use of many different functions including libSVM member functions to use SVMs to classify the kinect datasets \
Outputs the accuracy of the classification and the confusion matrix to the screen. \
\
BEST VALUES OF C and GAMMA: \
RAD: C: 2.0 \t Gamma: 2.0 \
HJPD: C: 32.0 \t Gamma: 2.0 \
HOD: C: 8.0 \t Gamma: 0.0078125 \

