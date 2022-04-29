#include <iostream>
#include "radInteg.cpp"
#include "hjpdInteg.cpp"
#include "hodInteg.cpp"
#include "svmFormatInteg.cpp"
#include "useSVMInteg.cpp"


// Prototypes
string getcwd();

int main(int argc, char** argv){
    Matrix test;
    string workingDirectory = getcwd();
    string trainName, testName;         // Filenames of test and train representations (unformatted)
    string trainFormatted, testFormatted;   // Filenames of test and train representations (formatted)

    // Generate Representations of Training and Testing Data 
    if (!strcmp("-r", argv[1])) {    // Entered command flag
        if (!strcmp("rad", argv[2])) {
            rad::rad(workingDirectory, true);    // RAD representation using train dataset
            rad::rad(workingDirectory, false);   // RAD representation using test dataset
            trainName = "rad_d1";
            testName = "rad_d1.t";
            trainFormatted = "rad_d2";
            testFormatted = "rad_d2.t";
        }
        else if (!strcmp("hjpd", argv[2])) {
            hjpd::hjpd(workingDirectory, true);   // HJPD representation using train dataset
            hjpd::hjpd(workingDirectory, false);  // HJPD representation using test dataset
            trainName = "hjpd_d1";
            testName = "hjpd_d1.t";
            trainFormatted = "hjpd_d2";
            testFormatted = "hjpd_d2.t";
        }
        else if (!strcmp("hod", argv[2])) {
            hod::hod(workingDirectory, true);   // HOD representation using train dataset
            hod::hod(workingDirectory, false);  // HOD representation using test dataset
            trainName = "hod_d1";
            testName = "hod_d1.t";
            trainFormatted = "hod_d2";
            testFormatted = "hod_d2.t";
        }
    }
    else {
        std::cout << "Error: please use the correct input arguments according to the README" << endl;
        exit(1);
    }

    // Format Data into libSVM standard
    int status;
    format(trainName, trainFormatted);        // Format training data representation into libSVM standard
    //remove(trainName.c_str());              // Delete original representation data after use
    format(testName, testFormatted);          // Format testing data representation into libSVM standard
    //remove(testName.c_str());               // Delete original representation data after use

    // Use libSVM
    useSVM(trainFormatted, testFormatted, atof(argv[3]), atof(argv[4]));

    // Delete data representation after finished (not in use for now)
    //remove(trainFormatted.c_str());
    //remove(testFormatted.c_str());

    return 0;





}


// Function to cleanly get working directory
string getcwd()
 {
     string out;
     char* buff = new char[255];    // Allocate memory
     out = string(getcwd(buff,255));
     delete[] buff;                 // Always remember to delete! :)
     return out;
 }