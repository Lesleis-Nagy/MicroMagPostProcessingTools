//
// Created by Lesleis Nagy on 23/07/2024.
//

#include <iostream>

#include <QVTKOpenGLNativeWidget.h>

#include <vtkPolyDataMapper.h>
#include <vtkCubeSource.h>
#include "vtkCylinderSource.h"
#include "vtkProperty.h"
#include "vtkCamera.h"

#include "MainWindow.hpp"

MainWindow::MainWindow() :
_bg_red(0.0), _bg_green(0.0), _bg_blue(0.0),
_actor_red(1.0), _actor_green(1.0), _actor_blue(1.0) {

  this->setupUi(this);

  // Create and assign a new vtkRenderer.
  _renderer = vtkSmartPointer<vtkRenderer>::New();
  _renderer->SetBackground(_bg_red, _bg_green, _bg_blue);
  _renderer->ResetCamera();
  _vtk_widget->renderWindow()->AddRenderer(_renderer);

  // Set the _current_actor to nullptr.
  _current_actor = nullptr;

  // Connect signals and slots.
  connect(_btn_cylinder, SIGNAL(clicked(bool)),
          this, SLOT(slot_btn_cylinder_clicked()));
  connect(_btn_clear, SIGNAL(clicked(bool)),
          this, SLOT(slot_btn_clear_clicked()));
  connect(_btn_cube, SIGNAL(clicked(bool)),
          this, SLOT(slot_btn_cube_clicked()));

}

void MainWindow::slot_btn_clear_clicked() {

  std::cout << "slot_btn_clear_clicked()" << std::endl;

  if (_current_actor.Get() != nullptr) {

    _renderer->RemoveActor(_current_actor);
    _current_actor = nullptr;

    _vtk_widget->update();
    _vtk_widget->renderWindow()->Render();

  }

}

void MainWindow::slot_btn_cylinder_clicked() {

  std::cout << "slot_btn_perform_clicked()" << std::endl;

  if (_current_actor.Get() == nullptr) {

    std::cout << "The current actor is empty, creating cylinder!" << std::endl;

    using PtrCylinderSource = vtkSmartPointer<vtkCylinderSource>;
    using PtrPolyDataMapper = vtkSmartPointer<vtkPolyDataMapper>;
    using PtrActor = vtkSmartPointer<vtkActor>;

    PtrCylinderSource cylinder_source = PtrCylinderSource::New();
    cylinder_source->SetResolution(300);

    PtrPolyDataMapper poly_data_mapper = PtrPolyDataMapper::New();
    poly_data_mapper->SetInputConnection(cylinder_source->GetOutputPort());

    _current_actor = PtrActor::New();
    _current_actor->SetMapper(poly_data_mapper);
    _current_actor->GetProperty()->SetColor(_actor_red, _actor_green, _actor_blue);
    _current_actor->RotateX(30.0);
    _current_actor->RotateY(-45.0);

    _renderer->AddActor(_current_actor);
    _renderer->ResetCamera();
    _renderer->GetActiveCamera()->Zoom(1.5);

    _vtk_widget->update();
    _vtk_widget->renderWindow()->Render();

  } else {

    std::cout << "There is already active actor!" << std::endl;

  }

}

void MainWindow::slot_btn_cube_clicked() {

  cout << "slot_btn_cube_clicked()" << std::endl;

  if (_current_actor.Get() == nullptr) {

    std::cout << "The current actor is empty, creating cube!" << std::endl;

    using PtrCubeSource = vtkSmartPointer<vtkCubeSource>;
    using PtrPolyDataMapper = vtkSmartPointer<vtkPolyDataMapper>;
    using PtrActor = vtkSmartPointer<vtkActor>;

    PtrCubeSource cube_source = PtrCubeSource::New();

    PtrPolyDataMapper poly_data_mapper = PtrPolyDataMapper::New();
    poly_data_mapper->SetInputConnection(cube_source->GetOutputPort());

    _current_actor = PtrActor::New();
    _current_actor->SetMapper(poly_data_mapper);
    _current_actor->GetProperty()->SetColor(_actor_red, _actor_green, _actor_blue);
    _current_actor->RotateX(30.0);
    _current_actor->RotateY(-45.0);

    _renderer->AddActor(_current_actor);
    _renderer->ResetCamera();
    _renderer->GetActiveCamera()->Zoom(1.5);

    _vtk_widget->update();
    _vtk_widget->renderWindow()->Render();

  } else {

    std::cout << "There is already active actor!" << std::endl;

  }

}