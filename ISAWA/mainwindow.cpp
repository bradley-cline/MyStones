#include "mainwindow.h"
#include "ui_mainwindow.h"

// Global
float totalCaratWeight = 0.0;




// ********************************************************************************
//                ~~~~~~~~~~~~~~  Ring Blank MAP  ~~~~~~~~~~~~~~
// ********************************************************************************
map<float,float> ringBlanks =
{{1,39.0}, {1.5,40.2}, {2,41.5}, {2.5,42.7}, {3,44.0}, {3.5,45.2},
 {4,46.5}, {4.5,47.8}, {5,49.0}, {5.5,50.3}, {6,51.5}, {6.5,52.8},
 {7,54.0}, {7.5,55.3}, {8,56.5}, {8.5,57.8}, {9,59.1}, {9.5,60.3},
 {10,61.6}, {10.5,62.8}, {11,64.1}, {11.5,65.3}, {12,66.6}, {12.5,67.9},
 {13,69.1}, {13.5,71.3}, {14,72.6}};





// ********************************************************************************
//                ~~~~~~~~~~~~~~  STONE CARAT MAPS  ~~~~~~~~~~~~~~
// ********************************************************************************


// Case 1: Round Stones Map
// Values for converting mm size to carat weight for round diamonds
map<float,float> roundStones =
{{0.0, 0.0}, {0.8, 0.0025}, {1.0, 0.005},
{1.12, 0.0067}, {1.15, 0.0075}, {1.25, 0.01},
{1.3, 0.015}, {1.75, 0.02}, {1.8, 0.025},
{2.0, 0.03}, {2.25, 0.04}, {2.5, 0.06},
{2.75, 0.08}, {3.0, 0.11}, {3.25, 0.14},
{3.5, 0.17}, {3.75, 0.21}, {4.0, 0.25},
{4.25, 0.28}, {4.5, 0.36}, {4.75, 0.44},
{5.0, 0.46}, {5.25, 0.56}, {5.5, 0.66},
{5.75, 0.76}, {6.0, 0.84}, {6.25, 0.93},
{6.5, 1.03}, {6.75, 1.24}, {7.0, 1.28},
{7.25, 1.49}, {7.5, 1.67}, {7.75, 1.75},
{8.0, 2.04}, {8.25, 2.11}, {8.5, 2.43}};

// Case 2: Princess Stones Map
// Values for converting mm size to carat weight for square diamonds
map<float,float> princessStones =
{{1.5, 0.015}, {1.75, 0.03}, {2, 0.06},
{2.25, 0.08}, {2.5, 0.1}, {2.75, 0.13},
{3, 0.18}, {3.25, 0.26}, {3.5, 0.29},
{3.75, 0.31}, {4, 0.39}, {4.25, 0.44},
{4.5, 0.56}, {4.75, 0.64}, {5, 0.71},
{5.25, 0.75}, {5.5, 0.99}, {5.75, 1.11},
{6, 1.24}, {6.25, 1.39}, {6.5, 1.59},
{6.75, 1.75}, {7, 1.96}, {7.25, 2.01},
{7.5, 2.4}, {7.75, 2.74}, {8, 3.01}};

// Case 3: Baguette Stones Map
// Values for converting mm size to carat weight for square diamonds
float longDim[62] = { 2, 2, 2, 2.25, 2.25, 2.5, 2.5, 2.5, 2.5, 2.5, 2.75, 2.75,
                       2.75, 2.75, 3, 3, 3, 3, 3, 3, 3.25, 3.25, 3.25, 3.25, 3.5,
                       3.5, 3.5, 3.5, 3.5, 3.5, 3.5, 3.75, 3.75, 4, 4, 4, 4, 4, 4.5,
                       4.5, 4.5, 4.5, 4.5, 4.5, 4.75, 4.75, 5, 5, 5, 5, 5, 5, 5,
                       5.5, 5.5, 5.5, 5.5, 5.5, 6, 6, 6, 6};

float shortDim[62] = {1, 1.5, 1.75, 1.75, 2, 1, 1.25, 1.5, 1.75, 2, 1.5, 1.75, 2, 2.5,
                      1, 1.25, 1.5, 1.75, 2, 2.5, 1.25, 1.5, 1.75, 2.5, 1, 1.25, 1.5,
                      1.75, 2, 2.5, 3, 1.5, 2, 1.25, 1.5, 1.75, 2, 3, 1.5, 1.75, 2, 2.5,
                      3, 3.5, 1.5, 2, 1.5, 1.75, 2, 2.5, 3, 3.5, 4, 1.75, 2, 2.5, 3,
                      3.5, 1.75, 2, 2.5, 3};

float baguetteCarat[62] = {0.02, 0.04, 0.04, 0.04, 0.045, 0.045, 0.047, 0.05, 0.055, 0.055,
                       0.055, 0.06, 0.06, 0.065, 0.05, 0.055, 0.06, 0.08, 0.1, 0.13,
                       0.06, 0.065, 0.08, 0.14, 0.065, 0.07, 0.07, 0.08, 0.13, 0.15,
                       0.15, 0.14, 0.145, 0.075, 0.08, 0.11, 0.14, 0.2, 0.1, 0.14, 0.17,
                       0.2, 0.285, 0.3, 0.27, 0.28, 0.14, 0.15, 0.19, 0.24, 0.3, 0.33,
                       0.4, 0.16, 0.18, 0.23, 0.3, 0.33, 0.28, 0.3, 0.33, 0.4};


// Case 4: Marquise Stones Arrays
// Values for converting mm size to carat weight for square diamonds
float marquiseLongDim[26] = { 3, 3.5, 3.5, 3.75, 4, 4.25, 5, 5, 5.5, 5.5, 6, 6.5, 7, 7, 7,
                            7.5, 8, 9, 9, 9.5, 10, 11, 11.5, 12, 12, 13};

float marquiseShortDim[26] = { 1.5, 1.75, 2, 1.75, 2, 2.25, 2.5, 3, 2.75, 3, 3, 3, 3, 3.5,
                             4, 3.5, 4, 4.5, 5, 2, 5, 5.5, 6, 6, 6.5, 6.5};

float marquiseCarat[26] = { 0.025, 0.065, 0.07, 0.11, 0.1, 0.12, 0.14, 0.2, 0.16, 0.18, 0.23,
                          0.25, 0.3, 0.33, 0.43, 0.35, 0.47, 0.71, 0.76, 0.85, 0.95, 1.25,
                          1.33, 1.62, 1.71, 2.11};


// Case 5: Pear Stones Arrays
// Values for converting mm size to carat weight for square diamonds
float pearLongDim[12] = { 3, 4, 4, 5, 5, 6, 6.5, 7, 8, 8, 8.5, 9};

float pearShortDim[12] = { 2, 2.5, 3, 3, 4, 4, 4.5, 5, 5, 6, 5.5, 6};

float pearCarat[12] = { 0.13, 0.18, 0.21, 0.25, 0.35, 0.39, 0.57, 0.71, 0.81, 1.25, 1.08, 1.33};




// Case 6: Oval Stones Arrays
// Values for converting mm size to carat weight for square diamonds
float ovalLongDim[10] = { 4.5, 5, 5, 5.5, 6, 6, 6.5, 7, 7.5, 8};

float ovalShortDim[10] = { 3.5, 3, 4, 3.5, 4, 5, 4.5, 5, 5.5, 6};

float ovalCarat[10] = { 0.21, 0.21, 0.35, 0.33, 0.43, 0.61, 0.65, 0.76, 0.98, 1.21};



// Case 7: Trillion Stones Map
// Values for Converting mm size to carat weight for trillion diamonds
map<float,float> trillionStones =
{{3, 0.12}, {3.5, 0.16}, {3.75, 0.19},
{4, 0.23}, {4.25, 0.27}, {4.5, 0.31},
{4.75, 0.37}, {5, 0.42}, {5.25, 0.49},
{5.5, 0.55}, {5.75, 0.64}, {6, 0.7},
{6.25, 0.75}, {6.5, 0.91}, {6.75, 0.98},
{7, 1.1}, {7.5, 1.21}, {8, 1.75},
{9, 2.35}};



// ******************************************************************************************************
//                ~~~~~~~~~~~~~~  Conversions from mm size to carat weight  ~~~~~~~~~~~~~~
// ******************************************************************************************************

// Converts mm size to carat weight for round stone
// mmSize argument is stone size in milimeters
// returns float value of carat weight
float MainWindow::roundMMtoCarat(float mmSize){
    float caratSize = 0.0;

    for(map<float,float>::iterator it = roundStones.begin(); it != roundStones.end(); ++it){
        if(it->first <= mmSize){
            caratSize = it->second;
        }else
            break;
    }
    return caratSize;
}

// Converts mm size to carat weight for square stone
// mmSize argument is stone size in milimeters
// returns float value of carat weight
float MainWindow::princessMMtoCarat(float mmSize){
    float caratSize = 0.0;

    for(map<float,float>::iterator it = princessStones.begin(); it != princessStones.end(); ++it){
        if(it->first <= mmSize){
            caratSize = it->second;
        }else
            break;
    }
    return caratSize;
}

// Converts mm size to carat weight for baguette stone
// mmSize argument is stone size in milimeters
// returns float value of carat weight
// Rounds down when possible
float MainWindow::baguetteMMtoCarat(float mmSize1, float mmSize2){
    float longSide;
    float shortSide;
    int longIndex = 0;
    int finalIndex = 0;

    // Find which dimension is larger
    if(mmSize2 > mmSize1){
        longSide = mmSize2;
        shortSide = mmSize1;
    }else{
        longSide = mmSize1;
        shortSide = mmSize2;
    }


    // Find Closest long side of the stone dimension
    for(int i = 0; i < 62; i++){
        if(longDim[i] == longSide){
            longIndex = i;
            finalIndex = i;
            break;
        }else if(longDim[i] < longSide){
            longIndex = i;
            finalIndex = i;
        }else{
            longSide = longDim[longIndex];
            break;
        }
    }

    // find closest short side of the stone dimension
    for(int i = 0; i < 62; i++){
        if(longDim[i] == longSide){     // only will proceed so long as the long dimension is still the same
            if(shortDim[i] == shortSide){
                finalIndex = i;
                break;
            }else if(shortDim[i] < shortSide){
                finalIndex = i;
            }else{
                break;
            }
        }
    }
    return baguetteCarat[finalIndex];
}


// Converts mm size to carat weight for marquise stone
// mmSize argument is stone size in milimeters
// returns float value of carat weight
// Rounds down when possible
float MainWindow::marquiseMMtoCarat(float mmSize1, float mmSize2){
    float longSide;
    float shortSide;
    int longIndex = 0;
    int finalIndex = 0;

    // Find which dimension is larger
    if(mmSize2 > mmSize1){
        longSide = mmSize2;
        shortSide = mmSize1;
    }else{
        longSide = mmSize1;
        shortSide = mmSize2;
    }


    // Find Closest long side of the stone dimension
    for(int i = 0; i < 26; i++){
        if(marquiseLongDim[i] == longSide){
            longIndex = i;
            finalIndex = i;
            break;
        }else if(marquiseLongDim[i] < longSide){
            longIndex = i;
            finalIndex = i;
        }else{
            longSide = marquiseLongDim[longIndex];
            break;
        }
    }

    // find closest short side of the stone dimension
    for(int i = 0; i < 26; i++){
        if(marquiseLongDim[i] == longSide){     // only will proceed so long as the long dimension is still the same
            if(marquiseShortDim[i] == shortSide){
                finalIndex = i;
                break;
            }else if(marquiseShortDim[i] < shortSide){
                finalIndex = i;
            }else{
                break;
            }
        }
    }
    return marquiseCarat[finalIndex];
}

// Converts mm size to carat weight for pear stone
// mmSize argument is stone size in milimeters
// returns float value of carat weight
// Rounds down when possible
float MainWindow::pearMMtoCarat(float mmSize1, float mmSize2){
    float longSide;
    float shortSide;
    int longIndex = 0;
    int finalIndex = 0;

    // Find which dimension is larger
    if(mmSize2 > mmSize1){
        longSide = mmSize2;
        shortSide = mmSize1;
    }else{
        longSide = mmSize1;
        shortSide = mmSize2;
    }


    // Find Closest long side of the stone dimension
    for(int i = 0; i < 12; i++){
        if(pearLongDim[i] == longSide){
            longIndex = i;
            finalIndex = i;
            break;
        }else if(pearLongDim[i] < longSide){
            longIndex = i;
            finalIndex = i;
        }else{
            longSide = pearLongDim[longIndex];
            break;
        }
    }

    // find closest short side of the stone dimension
    for(int i = 0; i < 12; i++){
        if(pearLongDim[i] == longSide){     // only will proceed so long as the long dimension is still the same
            if(pearShortDim[i] == shortSide){
                finalIndex = i;
                break;
            }else if(pearShortDim[i] < shortSide){
                finalIndex = i;
            }else{
                break;
            }
        }
    }
    return pearCarat[finalIndex];
}

// Converts mm size to carat weight for oval stone
// mmSize argument is stone size in milimeters
// returns float value of carat weight
// Rounds down when possible
float MainWindow::ovalMMtoCarat(float mmSize1, float mmSize2){
    float longSide;
    float shortSide;
    int longIndex = 0;
    int finalIndex = 0;

    // Find which dimension is larger
    if(mmSize2 > mmSize1){
        longSide = mmSize2;
        shortSide = mmSize1;
    }else{
        longSide = mmSize1;
        shortSide = mmSize2;
    }


    // Find Closest long side of the stone dimension
    for(int i = 0; i < 12; i++){
        if(ovalLongDim[i] == longSide){
            longIndex = i;
            finalIndex = i;
            break;
        }else if(ovalLongDim[i] < longSide){
            longIndex = i;
            finalIndex = i;
        }else{
            longSide = ovalLongDim[longIndex];
            break;
        }
    }

    // find closest short side of the stone dimension
    for(int i = 0; i < 12; i++){
        if(ovalLongDim[i] == longSide){     // only will proceed so long as the long dimension is still the same
            if(ovalShortDim[i] == shortSide){
                finalIndex = i;
                break;
            }else if(ovalShortDim[i] < shortSide){
                finalIndex = i;
            }else{
                break;
            }
        }
    }
    return ovalCarat[finalIndex];
}

// Converts mm size to carat weight for trillion stone
// mmSize argument is stone size in milimeters
// returns float value of carat weight
float MainWindow::trillionMMtoCarat(float mmSize){
    float caratSize = 0.0;

    for(map<float,float>::iterator it = trillionStones.begin(); it != trillionStones.end(); ++it){
        if(it->first <= mmSize){
            caratSize = it->second;
        }else
            break;
    }
    return caratSize;
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Sets Karat Multiplier for 10kt
void MainWindow::on_radioButton_clicked()
{
    kMultiplier = 140.0;
}


// Sets Karat Multiplier for 14kt
void MainWindow::on_radioButton_2_clicked()
{
    kMultiplier = 199.0;
}


// Sets Karat Multiplier for 18kt
void MainWindow::on_radioButton_3_clicked()
{
    kMultiplier = 265.0;
}



// Calculates Price from Stone Line
float MainWindow::stoneLineTotal(QComboBox *shape, QSpinBox *quantity, QDoubleSpinBox *dim1, QDoubleSpinBox *dim2, QCheckBox *hq)
{
    float lineTotal = 0.00;
    float caratWeightFromMM;

    switch (shape->currentIndex()) {
    case 0: // Blank stone shape
        //Later
        break;
    case 1: // Round stone shape
        caratWeightFromMM = roundMMtoCarat(dim1->value());
        totalCaratWeight += (float(caratWeightFromMM) * quantity->value());

        if(hq->checkState() == 0 && caratWeightFromMM <= 0.08) {
            lineTotal = quantity->value() * (600.00 * caratWeightFromMM);
        }else if(hq->checkState() == 2 && caratWeightFromMM <= 0.08) {
            lineTotal = quantity->value() * (1200.00 * caratWeightFromMM);
        }else if (caratWeightFromMM > 0.08 && caratWeightFromMM <= 0.18) {
            lineTotal = quantity->value() * (2100.00 * caratWeightFromMM);
        }else if (caratWeightFromMM > 0.18 && caratWeightFromMM <= 0.30) {
            lineTotal = quantity->value() * (2550.00 * caratWeightFromMM);
        }else if (caratWeightFromMM > 0.30 && caratWeightFromMM < 0.50) {
            lineTotal = quantity->value() * (2800.00 * caratWeightFromMM);
        }else if (caratWeightFromMM >= 0.50 && caratWeightFromMM < 0.73) {
            lineTotal = quantity->value() * (4100.00 * caratWeightFromMM);
        }else if (caratWeightFromMM >= 0.73 && caratWeightFromMM <= 0.91) {
            lineTotal = quantity->value() * (5400.00 * caratWeightFromMM);
        }else {
            lineTotal = -1.0;
        }
        break;
    case 2: // Princess stone shape
        caratWeightFromMM = princessMMtoCarat(dim1->value());
        totalCaratWeight += (float(caratWeightFromMM) * quantity->value());

        if(hq->checkState() == 0 && caratWeightFromMM <= 0.08) {
            lineTotal = quantity->value() * (600.00 * caratWeightFromMM);
        }else if(hq->checkState() == 2 && caratWeightFromMM <= 0.08) {
            lineTotal = quantity->value() * (1200.00 * caratWeightFromMM);
        }else if (caratWeightFromMM > 0.08 && caratWeightFromMM <= 0.18) {
            lineTotal = quantity->value() * (2100.00 * caratWeightFromMM);
        }else if (caratWeightFromMM > 0.18 && caratWeightFromMM <= 0.30) {
            lineTotal = quantity->value() * (2550.00 * caratWeightFromMM);
        }else if (caratWeightFromMM > 0.30 && caratWeightFromMM < 0.50) {
            lineTotal = quantity->value() * (2800.00 * caratWeightFromMM);
        }else if (caratWeightFromMM >= 0.50 && caratWeightFromMM < 0.73) {
            lineTotal = quantity->value() * (4100.00 * caratWeightFromMM);
        }else if (caratWeightFromMM >= 0.73 && caratWeightFromMM <= 0.91) {
            lineTotal = quantity->value() * (5400.00 * caratWeightFromMM);
        }else {
            lineTotal = -1.0;
        }
        break;
    case 3: // Baguette stone shape
        caratWeightFromMM = baguetteMMtoCarat(dim1->value(), dim2->value());
        totalCaratWeight += (float(caratWeightFromMM) * quantity->value());

        if(caratWeightFromMM <= 0.08) {
            lineTotal = quantity->value() * (600.00 * caratWeightFromMM);
        }else if (caratWeightFromMM > 0.08 && caratWeightFromMM <= 0.18) {
            lineTotal = quantity->value() * (2100.00 * caratWeightFromMM);
        }else if (caratWeightFromMM > 0.18 && caratWeightFromMM <= 0.30) {
            lineTotal = quantity->value() * (2550.00 * caratWeightFromMM);
        }else if (caratWeightFromMM > 0.30 && caratWeightFromMM < 0.50) {
            lineTotal = quantity->value() * (2800.00 * caratWeightFromMM);
        }else if (caratWeightFromMM >= 0.50 && caratWeightFromMM < 0.73) {
            lineTotal = quantity->value() * (4100.00 * caratWeightFromMM);
        }else if (caratWeightFromMM >= 0.73 && caratWeightFromMM <= 0.91) {
            lineTotal = quantity->value() * (5400.00 * caratWeightFromMM);
        }else {
            lineTotal = -1.0;
        }
        break;
    case 4: // Marquise stone shape
            caratWeightFromMM = marquiseMMtoCarat(dim1->value(), dim2->value());
            totalCaratWeight += (float(caratWeightFromMM) * quantity->value());

            if(caratWeightFromMM <= 0.08) {
                lineTotal = quantity->value() * (600.00 * caratWeightFromMM);
            }else if (caratWeightFromMM > 0.08 && caratWeightFromMM <= 0.18) {
                lineTotal = quantity->value() * (2100.00 * caratWeightFromMM);
            }else if (caratWeightFromMM > 0.18 && caratWeightFromMM <= 0.30) {
                lineTotal = quantity->value() * (2550.00 * caratWeightFromMM);
            }else if (caratWeightFromMM > 0.30 && caratWeightFromMM < 0.50) {
                lineTotal = quantity->value() * (2800.00 * caratWeightFromMM);
            }else if (caratWeightFromMM >= 0.50 && caratWeightFromMM < 0.73) {
                lineTotal = quantity->value() * (4100.00 * caratWeightFromMM);
            }else if (caratWeightFromMM >= 0.73 && caratWeightFromMM <= 0.91) {
                lineTotal = quantity->value() * (5400.00 * caratWeightFromMM);
            }else {
                lineTotal = -1.0;
            }
            break;
        case 5: // Pear stone shape
            caratWeightFromMM = pearMMtoCarat(dim1->value(), dim2->value());
            totalCaratWeight += (float(caratWeightFromMM) * quantity->value());

            if(caratWeightFromMM <= 0.08) {
                lineTotal = quantity->value() * (600.00 * caratWeightFromMM);
            }else if (caratWeightFromMM > 0.08 && caratWeightFromMM <= 0.18) {
                lineTotal = quantity->value() * (2100.00 * caratWeightFromMM);
            }else if (caratWeightFromMM > 0.18 && caratWeightFromMM <= 0.30) {
                lineTotal = quantity->value() * (2550.00 * caratWeightFromMM);
            }else if (caratWeightFromMM > 0.30 && caratWeightFromMM < 0.50) {
                lineTotal = quantity->value() * (2800.00 * caratWeightFromMM);
            }else if (caratWeightFromMM >= 0.50 && caratWeightFromMM < 0.73) {
                lineTotal = quantity->value() * (4100.00 * caratWeightFromMM);
            }else if (caratWeightFromMM >= 0.73 && caratWeightFromMM <= 0.91) {
                lineTotal = quantity->value() * (5400.00 * caratWeightFromMM);
            }else {
                lineTotal = -1.0;
            }
            break;
        case 6: // Oval stone shape
            caratWeightFromMM = ovalMMtoCarat(dim1->value(), dim2->value());
            totalCaratWeight += (float(caratWeightFromMM) * quantity->value());

            if(caratWeightFromMM <= 0.08) {
                lineTotal = quantity->value() * (600.00 * caratWeightFromMM);
            }else if (caratWeightFromMM > 0.08 && caratWeightFromMM <= 0.18) {
                lineTotal = quantity->value() * (2100.00 * caratWeightFromMM);
            }else if (caratWeightFromMM > 0.18 && caratWeightFromMM <= 0.30) {
                lineTotal = quantity->value() * (2550.00 * caratWeightFromMM);
            }else if (caratWeightFromMM > 0.30 && caratWeightFromMM < 0.50) {
                lineTotal = quantity->value() * (2800.00 * caratWeightFromMM);
            }else if (caratWeightFromMM >= 0.50 && caratWeightFromMM < 0.73) {
                lineTotal = quantity->value() * (4100.00 * caratWeightFromMM);
            }else if (caratWeightFromMM >= 0.73 && caratWeightFromMM <= 0.91) {
                lineTotal = quantity->value() * (5400.00 * caratWeightFromMM);
            }else {
                lineTotal = -1.0;
            }
            break;
    case 7: // Trillion stone shape
        caratWeightFromMM = trillionMMtoCarat(dim1->value());
        totalCaratWeight += (float(caratWeightFromMM) * quantity->value());

        if(hq->checkState() == 0 && caratWeightFromMM <= 0.08) {
            lineTotal = quantity->value() * (600.00 * caratWeightFromMM);
        }else if(hq->checkState() == 2 && caratWeightFromMM <= 0.08) {
            lineTotal = quantity->value() * (1200.00 * caratWeightFromMM);
        }else if (caratWeightFromMM > 0.08 && caratWeightFromMM <= 0.18) {
            lineTotal = quantity->value() * (2100.00 * caratWeightFromMM);
        }else if (caratWeightFromMM > 0.18 && caratWeightFromMM <= 0.30) {
            lineTotal = quantity->value() * (2550.00 * caratWeightFromMM);
        }else if (caratWeightFromMM > 0.30 && caratWeightFromMM < 0.50) {
            lineTotal = quantity->value() * (2800.00 * caratWeightFromMM);
        }else if (caratWeightFromMM >= 0.50 && caratWeightFromMM < 0.73) {
            lineTotal = quantity->value() * (4100.00 * caratWeightFromMM);
        }else if (caratWeightFromMM >= 0.73 && caratWeightFromMM <= 0.91) {
            lineTotal = quantity->value() * (5400.00 * caratWeightFromMM);
        }else {
            lineTotal = -1.0;
        }
        break;
    default:
        break;
    }


    return lineTotal;
}

// Calculate
// Calculates weight of item input by user and multiplies by kMultiplier to find gold weight total value
void MainWindow::on_calculatePB_released()
{
    float itemWeight = ui->weight->text().toFloat();
    float itemPrice = 0.00;
    QString price;
    QString stoneWeight;
    float stone1Tot = stoneLineTotal(ui->shape1,ui->quant1,ui->firstDim1,ui->secondDim1,ui->hq1);
    float stone2Tot = stoneLineTotal(ui->shape2,ui->quant2,ui->firstDim2,ui->secondDim2,ui->hq2);
    float stone3Tot = stoneLineTotal(ui->shape3,ui->quant3,ui->firstDim3,ui->secondDim3,ui->hq3);
    float stone4Tot = stoneLineTotal(ui->shape4,ui->quant4,ui->firstDim4,ui->secondDim4,ui->hq4);
    float stone5Tot = stoneLineTotal(ui->shape5,ui->quant5,ui->firstDim5,ui->secondDim5,ui->hq5);


    // If the weight field or the stone line total fields are NOT ZERO, Create the price
    // based on weight and stone value
    if(itemWeight || stone1Tot || stone2Tot || stone3Tot || stone4Tot || stone5Tot){
        itemWeight *= kMultiplier;
        itemPrice += itemWeight + stone1Tot + stone2Tot + stone3Tot + stone4Tot + stone5Tot;
        itemPrice /= 10;
        itemPrice = ceil(itemPrice);
        itemPrice *= 10;
        itemPrice -= 0.05;
        price = QString("$ %1").arg(QString::number(itemPrice,'f',2));
        ui->retailPrice->setText(price);

        itemPrice += 0.05;
        itemPrice /= 2;
        itemPrice -= 0.05;
        price = QString("$ %1").arg(QString::number(itemPrice,'f',2));
        ui->currentPrice->setText(price);
    }

    stoneWeight = QString("%1 ctw").arg(QString::number(totalCaratWeight,'f',2));
    ui->ctw->setText(stoneWeight);
    totalCaratWeight = 0.0;

}

// Clear all fields on reset
void MainWindow::on_resetPB_released()
{
    ui->weight->clear();
    ui->ctw->clear();
    ui->retailPrice->clear();
    ui->currentPrice->clear();

    ui->shape1->setCurrentIndex(0);
    ui->quant1->setValue(0);
    ui->firstDim1->setValue(0.00);
    ui->secondDim1->setValue(0.00);
    ui->hq1->setChecked(false);

    ui->shape2->setCurrentIndex(0);
    ui->quant2->setValue(0);
    ui->firstDim2->setValue(0.00);
    ui->secondDim2->setValue(0.00);
    ui->hq2->setChecked(false);

    ui->shape3->setCurrentIndex(0);
    ui->quant3->setValue(0);
    ui->firstDim3->setValue(0.00);
    ui->secondDim3->setValue(0.00);
    ui->hq3->setChecked(false);

    ui->shape4->setCurrentIndex(0);
    ui->quant4->setValue(0);
    ui->firstDim4->setValue(0.00);
    ui->secondDim4->setValue(0.00);
    ui->hq4->setChecked(false);

    ui->shape5->setCurrentIndex(0);
    ui->quant5->setValue(0);
    ui->firstDim5->setValue(0.00);
    ui->secondDim5->setValue(0.00);
    ui->hq5->setChecked(false);
}


// 1st Stone
void MainWindow::on_shape1_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        ui->quant1->setEnabled(false);
        ui->firstDim1->setEnabled(false);
        ui->secondDim1->setEnabled(false);
        ui->hq1->setEnabled(false);
        break;
    case 1:
        ui->quant1->setEnabled(true);
        ui->firstDim1->setEnabled(true);
        ui->secondDim1->setEnabled(false);
        ui->hq1->setEnabled(true);
        break;
    case 2:
    case 7:
        ui->quant1->setEnabled(true);
        ui->firstDim1->setEnabled(true);
        ui->secondDim1->setEnabled(false);
        ui->hq1->setEnabled(false);
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        ui->quant1->setEnabled(true);
        ui->firstDim1->setEnabled(true);
        ui->secondDim1->setEnabled(true);
        ui->hq1->setEnabled(false);
        break;
    default:
        break;
    }
}

// 2nd Stone
void MainWindow::on_shape2_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        ui->quant2->setEnabled(false);
        ui->firstDim2->setEnabled(false);
        ui->secondDim2->setEnabled(false);
        ui->hq2->setEnabled(false);
        break;
    case 1:
        ui->quant2->setEnabled(true);
        ui->firstDim2->setEnabled(true);
        ui->secondDim2->setEnabled(false);
        ui->hq2->setEnabled(true);
        break;
    case 2:
    case 7:
        ui->quant2->setEnabled(true);
        ui->firstDim2->setEnabled(true);
        ui->secondDim2->setEnabled(false);
        ui->hq2->setEnabled(false);
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        ui->quant2->setEnabled(true);
        ui->firstDim2->setEnabled(true);
        ui->secondDim2->setEnabled(true);
        ui->hq2->setEnabled(false);
        break;
    default:
        break;
    }
}

// 3rd Stone
void MainWindow::on_shape3_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        ui->quant3->setEnabled(false);
        ui->firstDim3->setEnabled(false);
        ui->secondDim3->setEnabled(false);
        ui->hq3->setEnabled(false);
        break;
    case 1:
        ui->quant3->setEnabled(true);
        ui->firstDim3->setEnabled(true);
        ui->secondDim3->setEnabled(false);
        ui->hq3->setEnabled(true);
        break;
    case 2:
    case 7:
        ui->quant3->setEnabled(true);
        ui->firstDim3->setEnabled(true);
        ui->secondDim3->setEnabled(false);
        ui->hq3->setEnabled(false);
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        ui->quant3->setEnabled(true);
        ui->firstDim3->setEnabled(true);
        ui->secondDim3->setEnabled(true);
        ui->hq3->setEnabled(false);
        break;
    default:
        break;
    }
}

// 4th Stone
void MainWindow::on_shape4_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        ui->quant4->setEnabled(false);
        ui->firstDim4->setEnabled(false);
        ui->secondDim4->setEnabled(false);
        ui->hq4->setEnabled(false);
        break;
    case 1:
        ui->quant4->setEnabled(true);
        ui->firstDim4->setEnabled(true);
        ui->secondDim4->setEnabled(false);
        ui->hq4->setEnabled(true);
        break;
    case 2:
    case 7:
        ui->quant4->setEnabled(true);
        ui->firstDim4->setEnabled(true);
        ui->secondDim4->setEnabled(false);
        ui->hq4->setEnabled(false);
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        ui->quant4->setEnabled(true);
        ui->firstDim4->setEnabled(true);
        ui->secondDim4->setEnabled(true);
        ui->hq4->setEnabled(false);
        break;
    default:
        break;
    }
}


// 5th Stone
void MainWindow::on_shape5_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        ui->quant5->setEnabled(false);
        ui->firstDim5->setEnabled(false);
        ui->secondDim5->setEnabled(false);
        ui->hq5->setEnabled(false);
        break;
    case 1:
        ui->quant5->setEnabled(true);
        ui->firstDim5->setEnabled(true);
        ui->secondDim5->setEnabled(false);
        ui->hq5->setEnabled(true);
        break;
    case 2:
    case 7:
        ui->quant5->setEnabled(true);
        ui->firstDim5->setEnabled(true);
        ui->secondDim5->setEnabled(false);
        ui->hq5->setEnabled(false);
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        ui->quant5->setEnabled(true);
        ui->firstDim5->setEnabled(true);
        ui->secondDim5->setEnabled(true);
        ui->hq5->setEnabled(false);
        break;
    default:
        break;
    }
}


void MainWindow::on_pushButton_released()
{
    float intake = ui->intakeWeight->text().toFloat();
    QString value;

    value = QString::number((intake*dwtMultiplier),'f',3);
    ui->dwtVal->setText(value);
    value = QString::number((intake*ozMultiplier),'f',3);
    ui->ozVal->setText(value);
    value = QString::number((intake*gMultiplier),'f',3);
    ui->gVal->setText(value);

    ui->calculatePB->setFlat(false);
}


void MainWindow::on_dwtIntake_clicked()
{
    dwtMultiplier = 1.0;
    ozMultiplier = 0.05;
    gMultiplier = 1.55517;
}


void MainWindow::on_ouncesIntake_clicked()
{
    dwtMultiplier = 20.0;
    ozMultiplier = 1.0;
    gMultiplier = 31.1035;
}


void MainWindow::on_gramsIntake_clicked()
{
    dwtMultiplier = 0.643015;
    ozMultiplier = 0.0321507;
    gMultiplier = 1.0;
}


float MainWindow::ringSizetoBlank(float rSize)
{
    float blankSize = 0.0;

    for(map<float,float>::iterator it = ringBlanks.begin(); it != ringBlanks.end(); ++it){
        if(it->first <= rSize){
            blankSize = it->second;
        }else
            break;
    }
    return blankSize;
}


void MainWindow::on_ringBlankCalculate_released()
{
    float mmBlank = ringSizetoBlank(ui->ringBlankIntake->text().toFloat());
    float inBlank = mmBlank / 25.4;
    QString blankVal;

    blankVal = QString::number(mmBlank,'f',1);
    ui->ringBlankLabel->setText(blankVal);

    blankVal = QString::number(inBlank,'f',2);
    ui->ringBlankInch->setText(blankVal);

}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString brandFile;
    QUrl infoBlock;
    brandFile = QString("/Users/Administrator/Desktop/Brad/ISAWA/BrandsForPartsFinder/%1.html").arg(item->text());


    infoBlock.setUrl(brandFile);
    ui->partsGroup->setTitle(item->text());
    ui->textBrowser->setSource(infoBlock);
}
