#include <iostream>
#include <fstream>
#include <ctype.h>
#include <math.h>
#include <vector>
#include <complex>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include "chartview.h"
#include <QtCharts/QScatterSeries>
#include <QtCharts/QLineSeries>

using namespace std;

unsigned long long int inputwavesize;


//Input string from file : YOU MIGHT HAVE A DIFFERENT BODY FOR THIS FUNCTION DEPENDING ON HOW THE INPUT FILE IS ORGANIZED
std::vector <double> InputWave(const char* filename)
{

    std::vector <double> mainwave;
    std::fstream file;
    std::string line;

    file.open(filename);

    double num;
    string numstr;


    while(!file.eof())
    {
        std::getline(file, line);

        if(isdigit(line[1]))
        {
            int countTab = 0;
            for(int i=0; i < (line.size()-6); i++)
            {

                if(line[i] == 9)                                      //check for tabs in line
                {
                    countTab++;                                       //count tabs in one line
                }

                else if(countTab == 4 && line[0] != NULL)
                {


                    for(int j=i; j < i+7; j++)
                    {
                        numstr = numstr + line[j];
                    }
                    std::cout<<numstr<<"\n";
                    num = std::stod(numstr);        //store the string type numbers as double
                    mainwave.push_back(num);
                    numstr = "";
                }
            }
        }
    }

    file.close();
    return mainwave;
}


//Return WaveSize
unsigned long long int wavesize(std::vector <double> inputwave)
{
    return inputwave.size();
}

//Display original wave
void displayoriginal(std::vector <double> inputwave)
{
    for(int i=0; i < inputwave.size(); i++)
    {
        std::cout << inputwave[i] << "\n";
    }
}


//MultiScale Analysis of the original wave
std::vector <std::vector <double> > multiscaling(std::vector <double> inputwave)
{

    std::cout<<"\n\n\n\n";

    std::vector <double> temp;
    std::vector <std::vector <double> > fi;
    std::vector <double> tempglob;

    for(int i=0; i < inputwave.size(); i++)
    {
        tempglob.push_back (inputwave[i]);
    }

    for(int i=0; i < tempglob.size(); i++)
    {
        temp.push_back(0);
    }

    for(int i=0; i < 11; i++)
    {
        fi.push_back(temp);
    }

    std::cout<<"\n\n";

    int k=1;
    for(int i=0; i < 10; i++)
    {
        k = k * 2;
        int sizeby2= tempglob.size()/k;

        for(int j=0; j < tempglob.size(); j=j+2)
        {
            if(j/2 < sizeby2)
            {
                fi[i][j/2] = (tempglob[j] + tempglob[j+1]) / (2.0);
                fi[i][(j/2)+sizeby2] = tempglob[j] - fi[i][j/2];
            }
        }

        for(int s=sizeby2; s < tempglob.size(); s++)
        {
            fi[i+1][s] = fi[i][s];
        }

        for(int p=0; p < tempglob.size(); p++)
        {
            tempglob[p] = fi[i][p];
        }

    }

    return fi;
}


//Chart Plot of Original Wave
MyChartView::MyChartView(std::vector <double> inputwave, QWidget *parent) :
    QChartView (new QChart(), parent)
{

    QLineSeries *series0 = new QLineSeries();

    series0->setName("Original Chart Plot");
    series0->setColor("green");

    for(int i=0; i < inputwavesize; i++)
    {
        series0->append(i, inputwave[i]);
    }

    setRenderHint(QPainter::Antialiasing);

    chart()->addSeries(series0);

    chart()->setTitle("Chart Plot");
    chart()->createDefaultAxes();
    chart()->setDropShadowEnabled(false);

    chart()->legend()->setMarkerShape(QLegend::MarkerShapeFromSeries);
}


//Chart Plot of MultiScales (10 scales)
MyChartView2::MyChartView2(std::vector <std::vector <double> > fi, QWidget *parent) :
    QChartView (new QChart(), parent)
{

    QLineSeries *series0 = new QLineSeries();
    series0->setName("1st");
    series0->setColor("red");

    for(int i=0; i < inputwavesize; i++)
    {
        series0->append(i, fi[0][i]);
    }

    QLineSeries *series1 = new QLineSeries();
    series1->setName("2nd");
    series1->setColor("blue");

    for(int i=0; i < inputwavesize; i++)
    {
        series1->append(i, fi[1][i]);
    }


    QLineSeries *series2 = new QLineSeries();
    series2->setName("3rd");
    series2->setColor("green");

    for(int i=0; i < inputwavesize; i++)
    {
        series2->append(i, fi[2][i]);
    }

    QLineSeries *series3 = new QLineSeries();
    series3->setName("4th");
    series3->setColor("pink");

    for(int i=0; i < inputwavesize; i++)
    {
        series3->append(i, fi[3][i]);
    }

    QLineSeries *series4 = new QLineSeries();
    series4->setName("5th");
    series4->setColor("orange");

    for(int i=0; i < inputwavesize; i++)
    {
        series4->append(i, fi[4][i]);
    }

    QLineSeries *series5 = new QLineSeries();
    series5->setName("6th");
    series5->setColor("yellow");

    for(int i=0; i < inputwavesize; i++)
    {
        series5->append(i, fi[5][i]);
    }

    QLineSeries *series6 = new QLineSeries();
    series6->setName("7th");
    series6->setColor("violet");

    for(int i=0; i < inputwavesize; i++)
    {
        series6->append(i, fi[6][i]);
    }

    QLineSeries *series7 = new QLineSeries();
    series7->setName("8th");
    series7->setColor("black");

    for(int i=0; i < inputwavesize; i++)
    {
        series7->append(i, fi[7][i]);
    }

    QLineSeries *series8 = new QLineSeries();
    series8->setName("9th");
    series8->setColor("grey");

    for(int i=0; i < inputwavesize; i++)
    {
        series8->append(i, fi[8][i]);
    }

    QLineSeries *series9 = new QLineSeries();
    series9->setName("10th");
    series9->setColor("indigo");

    for(int i=0; i < inputwavesize; i++)
    {
        series9->append(i, fi[9][i]);
    }

    setRenderHint(QPainter::Antialiasing);

    chart()->addSeries(series0);
    chart()->addSeries(series1);
    chart()->addSeries(series2);
    chart()->addSeries(series3);
    chart()->addSeries(series4);
    chart()->addSeries(series5);
    chart()->addSeries(series6);
    chart()->addSeries(series7);
    chart()->addSeries(series8);
    chart()->addSeries(series9);

    chart()->setTitle("Chart Plot of 10 scales");
    chart()->createDefaultAxes();
    chart()->setDropShadowEnabled(false);

    chart()->legend()->setMarkerShape(QLegend::MarkerShapeFromSeries);
}


//Thresholding the 10th scale
std::vector <std::vector <double> > thresholding(std::vector <std::vector <double> > fi)
{
    for(int i=0; i < inputwavesize; i++)
    {
        if(fi[9][i] < 0.02 && fi[9][i] > -0.02)
        {
            fi[9][i] = 0;
        }
    }

    return fi;
}


//Reconstruction of the wave from thresholded 10th scale
std::vector <std::vector <double> > reconstruct(std::vector <std::vector <double> > thresholdedmultiscale)
{
    int k = 1024;
    int sizeby2;

    for(int i=0; i < inputwavesize; i++)
    {
        thresholdedmultiscale[0][i] = NULL;
    }

    for(int i=0; i < inputwavesize; i++)
    {
        thresholdedmultiscale[10][i] = thresholdedmultiscale[9][i];
    }

    for(int i=10; i > 0; i--)
    {
        sizeby2 = (inputwavesize) / k;

        for(int j=0; j <= sizeby2*2; j=j+2)
        {
            thresholdedmultiscale[i-1][j] = thresholdedmultiscale[i][j/2] + thresholdedmultiscale[i][(sizeby2) + (j/2)];
            thresholdedmultiscale[i-1][j+1] = (thresholdedmultiscale[i][j/2]) - (thresholdedmultiscale[i][(sizeby2) + (j/2)]);
        }

        for(int s=sizeby2*2; s < inputwavesize; s++)
        {
            thresholdedmultiscale[i-1][s] = thresholdedmultiscale[i][s];
        }

        k = k / 2;
    }

    return thresholdedmultiscale;
}


//Chart Plot of Reconstructed Denoised Wave
MyChartView3::MyChartView3(std::vector <std::vector <double> > reconstructed2d, QWidget *parent) :
    QChartView (new QChart(), parent)
{

    QLineSeries *series0 = new QLineSeries();

    series0->setName("Thresholded Chart Plot");
    series0->setColor("green");

    for(int i=0; i < inputwavesize; i++)
    {
        series0->append(i, reconstructed2d[0][i]);
    }

    setRenderHint(QPainter::Antialiasing);

    chart()->addSeries(series0);

    chart()->setTitle("Chart Plot of Reconstructed Denoised Wave");
    chart()->createDefaultAxes();
    chart()->setDropShadowEnabled(false);

    chart()->legend()->setMarkerShape(QLegend::MarkerShapeFromSeries);
}


//Main Function
int main(int argc, char *argv[])
{

    const char *filename = "<add your file path>";

    std::vector <double> inputwave = InputWave(filename);
    inputwavesize = wavesize(inputwave);

    std::vector <std::vector <double> > fi = multiscaling(inputwave);
    std::vector <std::vector <double> > thresholdedmultiscale = thresholding(fi);
    std::vector <std::vector <double> > reconstructed2d = reconstruct(thresholdedmultiscale);

    //displayoriginal(inputwave);

    std::cout<<"\n\n\n";


    QApplication a(argc, argv);


    MyChartView *chartview = new MyChartView(inputwave);
    MyChartView2 *chartview2 = new MyChartView2(fi);
    MyChartView3 *chartview3 = new MyChartView3(reconstructed2d);

    QMainWindow window;
    window.setCentralWidget(chartview);
    window.resize(1920, 1000);
    window.show();


    QMainWindow window2;
    window2.setCentralWidget(chartview2);
    window2.resize(1920, 1000);
    window2.show();


    QMainWindow window3;
    window3.setCentralWidget(chartview3);
    window3.resize(1920, 1000);
    window3.show();

    return a.exec();

}
