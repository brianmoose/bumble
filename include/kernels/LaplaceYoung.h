/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef LAPLACEYOUNG_H
#define LAPLACEYOUNG_H

#include "Kernel.h"

class LaplaceYoung;

template<>
InputParameters validParams<LaplaceYoung>();


class LaplaceYoung : public Kernel
{
public:
  LaplaceYoung(const InputParameters & parameters);
  virtual ~LaplaceYoung();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
};


#endif /* LAPLACEYOUNG_H */
