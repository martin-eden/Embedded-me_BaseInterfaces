// Base interfaces for this framework

/*
  Author: Martin Eden
  Last mod.: 2025-08-27
*/

/*
  "Interfaces" (aka "contracts" aka "prototypes") in this context
  are function signatures and abstract classes.

  They are used by some implementations to wrap lower-level functions
  to provide access to them via more generic methods.

  This increases low-level code bioavailability.
*/

#pragma once

#include <me_BaseTypes.h>

// We will remain in root namespace

// Input stream concept
class IInputStream
{
  public:
    virtual TBool Read(TUnit * Unit) = 0;
};

// Output stream concept
class IOutputStream
{
  public:
    virtual TBool Write(TUnit Unit) = 0;
};



/*
  2025-08-27
*/
