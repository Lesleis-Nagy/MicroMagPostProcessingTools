//
// Created by Lesleis Nagy on 23/07/2024.
//

#ifndef VCOMPARE_TOY_QT_VTK_MAINWINDOWS_HPP_
#define VCOMPARE_TOY_QT_VTK_MAINWINDOWS_HPP_

#include <QMainWindow>

#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow, private Ui::MainWindow {
  Q_OBJECT

 public:

  MainWindow();
  ~MainWindow() override = default;

 private:

  double _bg_red;
  double _bg_green;
  double _bg_blue;

  double _actor_red;
  double _actor_green;
  double _actor_blue;

  vtkSmartPointer<vtkRenderer> _renderer;

  vtkSmartPointer<vtkActor> _cylinder_actor;
  vtkSmartPointer<vtkActor> _plane_actor;

};

#endif // VCOMPARE_TOY_QT_VTK_MAINWINDOWS_HPP_
