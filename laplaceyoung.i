[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 100
  ny = 100
  xmax = 1.0
  ymax = 1.0
[]

[Variables]
  [./u]
  [../]
[]

[Kernels]
  [./diff]
    type = LaplaceYoung
    variable = u
  [../]
[]

[BCs]
  [./all]
    type = NeumannBC
    variable = u
    boundary = 'left right top bottom'
    value = 0.2
  [../]
[]

[Executioner]
  type = Steady
  solve_type = 'PJFNK'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
