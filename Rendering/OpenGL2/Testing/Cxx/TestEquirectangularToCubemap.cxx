/*=========================================================================

  Program:   Visualization Toolkit
  Module:    TestEquirectangularToCubemap.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "vtkRegressionTestImage.h"
#include "vtkTestUtilities.h"

#include "vtkEquirectangularToCubemapTexture.h"
#include "vtkJPEGReader.h"
#include "vtkOpenGLTexture.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkSkybox.h"

int TestEquirectangularToCubemap(int argc, char* argv[])
{
  vtkNew<vtkRenderWindow> renWin;
  renWin->SetSize(400, 400);

  vtkNew<vtkRenderWindowInteractor> iren;
  iren->SetRenderWindow(renWin);

  vtkNew<vtkRenderer> renderer;
  renWin->AddRenderer(renderer);

  vtkNew<vtkJPEGReader> reader;
  reader->SetFileName(vtkTestUtilities::ExpandDataFileName(argc, argv, "Data/autoshop.jpg"));

  vtkNew<vtkTexture> texture;
  texture->SetInputConnection(reader->GetOutputPort());

  vtkNew<vtkEquirectangularToCubemapTexture> cubemap;
  cubemap->SetInputTexture(vtkOpenGLTexture::SafeDownCast(texture));

  vtkNew<vtkSkybox> world;
  world->SetTexture(cubemap);
  renderer->AddActor(world);

  renWin->Render();

  int retVal = vtkRegressionTestImage(renWin);
  if (retVal == vtkRegressionTester::DO_INTERACTOR)
  {
    iren->Start();
  }

  return !retVal;
}
