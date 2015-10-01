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
  p.addParam<Real>("kappa", 1.0, "Kappa");
  return p;
}

LaplaceYoung::LaplaceYoung(const InputParameters & parameters) :
    Kernel(parameters),
	_kappa(getParam<Real>("kappa"))
{
}

LaplaceYoung::~LaplaceYoung()
{
}

Real
LaplaceYoung::computeQpResidual()
{
  Real k = 1.0 / sqrt(1.0 + _grad_u[_qp]*_grad_u[_qp]);
  return k * _grad_u[_qp] * _grad_test[_i][_qp] + _kappa * _u[_qp]*_test[_i][_qp];
}

Real
LaplaceYoung::computeQpJacobian()
{
  Real k = 1.0 / sqrt(1.0 + _grad_u[_qp]*_grad_u[_qp]);
  Real dkdu = -std::pow(1. + _grad_u[_qp]*_grad_u[_qp], -1.5);
  return dkdu * (_grad_u[_qp] * _grad_phi[_j][_qp]) * (_grad_u[_qp]*_grad_test[_i][_qp])
    + k * _grad_phi[_j][_qp] * _grad_test[_i][_qp] + _kappa * _phi[_j][_qp]*_test[_i][_qp];
}

