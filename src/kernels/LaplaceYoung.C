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

#include "LaplaceYoung.h"


template<>
InputParameters validParams<LaplaceYoung>()
{
  InputParameters p = validParams<Kernel>();
  return p;
}

LaplaceYoung::LaplaceYoung(const InputParameters & parameters) :
    Kernel(parameters)
{
}

LaplaceYoung::~LaplaceYoung()
{
}

Real
LaplaceYoung::computeQpResidual()
{
  return _grad_u[_qp] * _grad_test[_i][_qp];
}

Real
LaplaceYoung::computeQpJacobian()
{
  return _grad_phi[_j][_qp] * _grad_test[_i][_qp];
}

