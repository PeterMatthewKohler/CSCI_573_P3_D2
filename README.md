Compilation and Execution Instructions: \
\
1.) Extract the folder from the tarball into a single location. Ensure that all the files extracted are in the same folder. \
2.) Open a terminal inside the folder that contains the extracted files \
3.) Use the command "make" \
4.) The integrated program that fulfills Task 4 in the Deliverable 2 writeup is called "integrated.cpp" and will be compiled into an executable called "integrated". \
5.) This program has 4 required input arguments. \
i.) "-r" which is a command line flag to signal which model you want \
ii.) The model can be one of three choices for each of the three representations: "rad", "hjpd", or "hod" \
iii.) The desired C parameter value \
iv.) The desired gamma parameter value \
Example command line usage: ./integrated -r rad 2 2 \
\
Implementation Information: \
For all 3 representations: for detected NAN values, the whole frame containing even a single NAN value is deleted. \
\
RAD: \
The Joints used for the angle and distance calculations are the joints 1, 4, 8, 12, 16, and 20. \
The number of bins used in this implementation is 16. \
The bin width is a determined from calculating the residual of the maximum data value and the minimum data value in the set, and then dividing by the number of bins. \
The histogram is normalized according to the number of frames. \
HJPD: \
The number of bins in each histogram is 18.\
The bin width is a determined from calculating the residual of the maximum data value and the minimum data value in the set, and then dividing by the number of bins. \
The histogram is normalized according to the total number of data points \
HOD: \
The number of bins used in the HOD histograms is 25. \
The bin width is 14 degrees per bin. \
The histogram uses the distance's magnitude as the real-value count and then is normalized by the total distance traveled in the joint's trajectory.

SVMF: \
Function to format the representations so they are usable by libSVM. Follows the required libSVM format of: \
[label] [index1]:[value1] [index2]:[value2]...

SUBMISSION MATERIALS:

INTEGRATED: \
Makes use of many different functions including libSVM member functions to use SVMs to classify the kinect datasets \
Generates all the representation files including the original representation files, then formats them to the libSVM standard \
Outputs the accuracy of the classification and the confusion matrix to the screen. \
Also generates the prediction file which ends in .predict \
\
GRID SEARCH GRAPHS: \
The graphs from the grid.py program are located in the folder "Graphs"

BEST VALUES OF C and GAMMA FOR THE ABOVE BIN SIZES: \
RAD: C: 2.0 Gamma: 2.0 \
HJPD: C: 2.0 Gamma: 8.0 \
HOD: C: 8.0 Gamma: 0.0078125

CONVERTED REPRESENTATION FILES and OUTPUT PREDICTION RESULT FILES \
The converted representation files are in the folder "Converted_Representations" \
and the Output Predictions are in the folder "Output_predictions"

ACCURACY FIGURES \
The accuracy vs. number of bins figures are in the folder "Accuracy_Figures" 


