#ifndef BUMBLEAPP_H
#define BUMBLEAPP_H

#include "MooseApp.h"

class BumbleApp;

template<>
InputParameters validParams<BumbleApp>();

class BumbleApp : public MooseApp
{
public:
  BumbleApp(InputParameters parameters);
  virtual ~BumbleApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* BUMBLEAPP_H */
