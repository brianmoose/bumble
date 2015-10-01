#include "BumbleApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<BumbleApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

BumbleApp::BumbleApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  BumbleApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  BumbleApp::associateSyntax(_syntax, _action_factory);
}

BumbleApp::~BumbleApp()
{
}

// External entry point for dynamic application loading
extern "C" void BumbleApp__registerApps() { BumbleApp::registerApps(); }
void
BumbleApp::registerApps()
{
  registerApp(BumbleApp);
}

// External entry point for dynamic object registration
extern "C" void BumbleApp__registerObjects(Factory & factory) { BumbleApp::registerObjects(factory); }
void
BumbleApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void BumbleApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { BumbleApp::associateSyntax(syntax, action_factory); }
void
BumbleApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
