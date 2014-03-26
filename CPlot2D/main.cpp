//
//  main.cpp
//  cplot2ddriver
//
//  Created by Attila Michael Zsaki on 14-03-21.
//  Copyright (c) 2014 Attila Michael Zsaki. All rights reserved.
//

#include <iostream>
#include <math.h>

#include "CPlot2D.h"

void TestTrigFunctions();
void TestMarkerStyles(bool filledMarker, bool noMarker, string fileName);
void TestLineStyles(int gridStyle, bool xAxisGrid, bool yAxisGrid);
void TestAxisLabels();

int main(int argc, const char * argv[])
{
    
    TestTrigFunctions();
    
    TestMarkerStyles(true,false,"test2_marker_styles_a.ps");
    TestMarkerStyles(false,false,"test2_marker_styles_b.ps");
    TestMarkerStyles(true,true,"test2_marker_styles_c.ps");
    
    TestLineStyles(0,true,true);
    TestLineStyles(1,true,true);
    TestLineStyles(2,true,true);
    
    TestAxisLabels();
    
    
    return 0;
}


void TestTrigFunctions()
{
    CPlot2D *plot2D=new CPlot2D();
    
    CDataSet dataSet;
    
    CDataPoint point;
    
    for (double x=-3.1515;x<=3.2;x+=0.1) {
        point.SetValues(x,sin(x));
        dataSet.AddDataPoint(point);
    }
    dataSet.SetDatasetColor(0.0,0.0,0.0);
    dataSet.SetDatasetTitle("sin(x)");
    
    plot2D->AddDataSet(dataSet);
    
    
    CDataSet dataSet1;
    
    for (double x=-3.1515;x<=3.2;x+=0.1) {
        point.SetValues(x,cos(x));
        dataSet1.AddDataPoint(point);
    }
    dataSet1.SetDatasetColor(1.0,0.0,0.0);
    dataSet1.SetDatasetTitle("cos(x)");
    
    plot2D->AddDataSet(dataSet1);
    
    
    CDataSet dataSet2;
    
    for (double x=-3.1515;x<=3.2;x+=0.1) {
        point.SetValues(x,sin(x)*cos(x));
        dataSet2.AddDataPoint(point);
    }
    dataSet2.SetDatasetColor(0.0,0.0,1.0);
    dataSet2.SetDatasetTitle("sin(x)*cos(x)");
    
    plot2D->AddDataSet(dataSet2);
    
    plot2D->SetXAxisTitle("variable x");
    plot2D->SetYAxisTitle("function");
    
    plot2D->OutputPostScriptPlot("test1_trigfunctions.ps");
}

void TestMarkerStyles(bool filledMarker, bool noMarker, string fileName)
{
    
    CPlot2D *plot2D=new CPlot2D();
    
    CDataSet dataSet[6];
    CDataPoint point;
    
    
    for (int i=0;i<6;++i) {
        for (double x=0.0;x<=3.2;x+=0.1) {
            point.SetValues(x,10.0*sin(x)+4.0*sin(3.0*x)+i);
            dataSet[i].AddDataPoint(point);
        }
        if (!filledMarker) {
            dataSet[i].SetDrawMarkerFilled(false);
        }
        if (noMarker) {
            dataSet[i].SetDrawMarker(false);
        }
    }
    
    dataSet[0].SetDatasetColor(0.0,0.0,0.0);
    dataSet[0].SetMarkerSymbol("o");
    dataSet[0].SetDatasetTitle("o");
    plot2D->AddDataSet(dataSet[0]);
    
    dataSet[1].SetDatasetColor(0.0,0.0,0.0);
    dataSet[1].SetMarkerSymbol("x");
    dataSet[1].SetDatasetTitle("x");
    plot2D->AddDataSet(dataSet[1]);
    
    dataSet[2].SetDatasetColor(0.0,0.0,0.0);
    dataSet[2].SetMarkerSymbol("*");
    dataSet[2].SetDatasetTitle("*");
    plot2D->AddDataSet(dataSet[2]);
    
    dataSet[3].SetDatasetColor(0.0,0.0,0.0);
    dataSet[3].SetMarkerSymbol("diamond");
    dataSet[3].SetDatasetTitle("diamond");
    plot2D->AddDataSet(dataSet[3]);
    
    dataSet[4].SetDatasetColor(0.0,0.0,0.0);
    dataSet[4].SetMarkerSymbol("square");
    dataSet[4].SetDatasetTitle("square");
    plot2D->AddDataSet(dataSet[4]);
    
    dataSet[5].SetDatasetColor(0.0,0.0,0.0);
    dataSet[5].SetMarkerSymbol("triangle");
    dataSet[5].SetDatasetTitle("triangle");
    plot2D->AddDataSet(dataSet[5]);
    
    plot2D->OutputPostScriptPlot(fileName);
}

void TestLineStyles(int gridStyle, bool xAxisGrid, bool yAxisGrid)
{
    
    CPlot2D *plot2D=new CPlot2D();
    
    CDataSet dataSet[4];
    CDataPoint point;
    
    
    for (int i=0;i<4;++i) {
        for (double x=0.0;x<=3.2;x+=0.2) {
            point.SetValues(x,10.0*sin(x)+4.0*cos(3.0*x)+3.0*i);
            dataSet[i].AddDataPoint(point);
        }
    }
    
    dataSet[0].SetDatasetColor(0.0,0.0,0.0);
    dataSet[0].SetDatasetTitle("solid");
    plot2D->AddDataSet(dataSet[0]);
    
    dataSet[1].SetDatasetColor(0.0,0.0,0.0);
    dataSet[1].SetDashedLine(true);
    dataSet[1].SetDashedLinePattern("dash");
    dataSet[1].SetDatasetTitle("dash");
    plot2D->AddDataSet(dataSet[1]);
    
    dataSet[2].SetDatasetColor(0.0,0.0,0.0);
    dataSet[2].SetDashedLine(true);
    dataSet[2].SetDashedLinePattern("dot");
    dataSet[2].SetDatasetTitle("dot");
    plot2D->AddDataSet(dataSet[2]);
    
    dataSet[3].SetDatasetColor(0.0,0.0,0.0);
    dataSet[3].SetDashedLine(true);
    dataSet[3].SetDashedLinePattern("dash_dot");
    dataSet[3].SetDatasetTitle("dash_dot");
    plot2D->AddDataSet(dataSet[3]);
    
    if (gridStyle==0) {
        plot2D->SetDrawXAxisGridLines(true);
        plot2D->SetDrawYAxisGridLines(true);
        plot2D->SetDrawGridLinesDashed(false);
        plot2D->OutputPostScriptPlot("test4_grid_lines_solid.ps");
        plot2D->SetDrawXAxisGridLines(false);
        plot2D->SetDrawYAxisGridLines(false);
        plot2D->OutputPostScriptPlot("test4_no_grid_lines.ps");
    }
    if (gridStyle==1) {
        plot2D->SetDrawGridLinesDashed(true);
        plot2D->SetDrawXAxisGridLines(true);
        plot2D->SetDrawYAxisGridLines(true);
        plot2D->OutputPostScriptPlot("test4_grid_lines_dashed.ps");
    }
    if (gridStyle==2) {
        plot2D->SetDrawXAxisGridLines(true);
        plot2D->SetDrawYAxisGridLines(false);
        plot2D->OutputPostScriptPlot("test4_no_x_axis_grid_lines.ps");
        plot2D->SetDrawXAxisGridLines(false);
        plot2D->SetDrawYAxisGridLines(true);
        plot2D->OutputPostScriptPlot("test4_no_y_axis_grid_lines.ps");
    }
}

void TestAxisLabels()
{
    
    CPlot2D *plot2D=new CPlot2D();
    
    CDataSet dataSet;
    CDataPoint point;
    
    
    for (double x=-100.01;x<=100.0;x+=10.0) {
        point.SetValues(x,x*x*x-x*x+x);
        dataSet.AddDataPoint(point);
    }
    
    
    dataSet.SetDatasetColor(0.0,1.0,0.0);
    dataSet.SetDatasetTitle("x^3-x^2+x");
    plot2D->AddDataSet(dataSet);
    
    plot2D->SetXAxisTitle("x axis");
    plot2D->SetYAxisTitle("y=x^3-x^2+x axis");
    
    plot2D->SetLeftFrameSize(100.0);
    
    plot2D->OutputPostScriptPlot("test5_axis_labels.ps");
    
}


