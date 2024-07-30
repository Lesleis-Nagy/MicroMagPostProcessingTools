//
// Created by Lesleis Nagy on 23/07/2024.
//

#include <iostream>

#include <QVTKOpenGLNativeWidget.h>

#include <vtkPolyDataMapper.h>
#include <vtkCubeSource.h>
#include "vtkCylinderSource.h"
#include "vtkPlaneSource.h"
#include "vtkProperty.h"
#include "vtkCamera.h"

#include "MainWindow.hpp"

MainWindow::MainWindow() :
_bg_red(0.0), _bg_green(0.0), _bg_blue(0.0),
_actor_red(1.0), _actor_green(1.0), _actor_blue(1.0) {

  using PtrCylinderSource = vtkSmartPointer<vtkCylinderSource>;
  using PtrPlaneSource = vtkSmartPointer<vtkPlaneSource>;
  using PtrPolyDataMapper = vtkSmartPointer<vtkPolyDataMapper>;
  using PtrActor = vtkSmartPointer<vtkActor>;

  this->setupUi(this);

  // Create and assign a new vtkRenderer.
  _renderer = vtkSmartPointer<vtkRenderer>::New();
  _renderer->SetBackground(_bg_red, _bg_green, _bg_blue);
  _renderer->ResetCamera();
  _vtk_widget->renderWindow()->AddRenderer(_renderer);

  // Set the _cylinder_actor.
  PtrCylinderSource cylinder_source = PtrCylinderSource::New();
  cylinder_source->SetResolution(300);
  cylinder_source->Update();

  PtrPolyDataMapper cylinder_poly_data_mapper = PtrPolyDataMapper::New();
  cylinder_poly_data_mapper->SetInputConnection(cylinder_source->GetOutputPort());

  _cylinder_actor = PtrActor::New();
  _cylinder_actor->SetMapper(cylinder_poly_data_mapper);
  _cylinder_actor->GetProperty()->SetColor(_actor_red, _actor_green, _actor_blue);
  _cylinder_actor->RotateX(30.0);
  _cylinder_actor->RotateY(-45.0);

  _renderer->AddActor(_cylinder_actor);

  // Set the plane _plane_actor.
  PtrPlaneSource plane_source = PtrPlaneSource::New();
  plane_source->SetResolution(10, 10);
  //plane_source->SetOrigin(0, 0, 0);
  //plane_source->SetPoint1( 0, 1, 0 );
  //plane_source->SetPoint2( 1, 0, 0 );
  plane_source->SetCenter(1, 1, 1);
  plane_source->SetNormal(1, 0, 0);
  plane_source->Update();

  PtrPolyDataMapper plane_poly_data_mapper = PtrPolyDataMapper::New();
  plane_poly_data_mapper->SetInputConnection(plane_source->GetOutputPort());

  _plane_actor = PtrActor::New();
  _plane_actor->SetMapper(plane_poly_data_mapper);
  _plane_actor->GetProperty()->SetColor(_actor_red, _actor_green, _actor_blue);

  _renderer->AddActor(_plane_actor);

  // Finalize the _renderer.
  _renderer->ResetCamera();
  _renderer->GetActiveCamera()->Zoom(1.0);

}
