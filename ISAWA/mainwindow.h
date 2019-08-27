#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <math.h>
#include <map>
#include <QComboBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QFile>
#include <QTextStream>
#include <QListWidgetItem>

using std::map;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_calculatePB_released();

    void on_resetPB_released();

    void on_shape1_currentIndexChanged(int index);

    void on_shape2_currentIndexChanged(int index);

    void on_shape3_currentIndexChanged(int index);

    void on_shape4_currentIndexChanged(int index);

    void on_shape5_currentIndexChanged(int index);

    void on_pushButton_released();

    void on_dwtIntake_clicked();

    void on_ouncesIntake_clicked();

    void on_gramsIntake_clicked();

    void on_ringBlankCalculate_released();

    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    float kMultiplier = 0.0;
    float dwtMultiplier = 0.0;
    float ozMultiplier = 0.0;
    float gMultiplier = 0.0;
    float roundMMtoCarat(float mmSize);
    float princessMMtoCarat(float mmSize);
    float baguetteMMtoCarat(float mmSize1, float mmSize2);
    float marquiseMMtoCarat(float mmSize1, float mmSize2);
    float pearMMtoCarat(float mmSize1, float mmSize2);
    float ovalMMtoCarat(float mmSize1, float mmSize2);
    float trillionMMtoCarat(float mmSize);
    float stoneLineTotal(QComboBox* shape, QSpinBox* quantity, QDoubleSpinBox* dim1, QDoubleSpinBox* dim2, QCheckBox* hq);
    float ringSizetoBlank(float rSize);
};



#endif // MAINWINDOW_H
