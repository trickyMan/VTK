/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkImageCorrelation.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkImageCorrelation - Correlation imageof the two inputs.
// .SECTION Description
// vtkImageCorrelation finds the correlation between two data sets. 
// SetDimensionality determines
// whether the Correlation will be 3D, 2D or 1D.  
// The default is a 2D Correlation.  The Output type will be double.
// The output size will match the size of the first input.
// The second input is considered the correlation kernel.

#ifndef __vtkImageCorrelation_h
#define __vtkImageCorrelation_h



#include "vtkThreadedImageAlgorithm.h"

class VTK_IMAGING_EXPORT vtkImageCorrelation : public vtkThreadedImageAlgorithm
{
public:
  static vtkImageCorrelation *New();
  vtkTypeRevisionMacro(vtkImageCorrelation,vtkThreadedImageAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);
  
  // Description:
  // Determines how the input is interpreted (set of 2d slices ...)
  vtkSetClampMacro(Dimensionality,int,2,3);
  vtkGetMacro(Dimensionality,int);
  
  // Description:
  // Set the two inputs to this filter
  virtual void SetInput1(vtkDataObject *in) { this->SetInput(0,in); }
  virtual void SetInput2(vtkDataObject *in) { this->SetInput(1,in); }

protected:
  vtkImageCorrelation();
  ~vtkImageCorrelation() {};

  int Dimensionality;
  void RequestInformation (vtkInformation *, 
                           vtkInformationVector **, vtkInformationVector *);
  virtual void RequestUpdateExtent(vtkInformation*,
                                   vtkInformationVector**,
                                   vtkInformationVector*);
  
  virtual void ThreadedRequestData(vtkInformation *request, 
                                   vtkInformationVector **inputVector, 
                                   vtkInformationVector *outputVector,
                                   vtkImageData ***inData, 
                                   vtkImageData **outData,
                                   int extent[6], int threadId);

private:
  vtkImageCorrelation(const vtkImageCorrelation&);  // Not implemented.
  void operator=(const vtkImageCorrelation&);  // Not implemented.
};

#endif



