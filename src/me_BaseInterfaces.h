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

/*
  Method call

  Three-address structure

  With dynamic functions generation we can reduce any call to
  one address.

  It's possible to reduce any call to two addresses but requires
  packing data in instance.

  Three addresses are quite convenient to call void methods.
*/
typedef void (*TMethod)(TAddress Data, TAddress Instance);

/*
  Failable operation

  Aka boolean method call.

  More convenience for some processing tasks.
*/
typedef TBool (*TOperation)(TAddress Data, TAddress Instance);

/*
  Failable operation with one argument

  Useful for stream input/output.
*/
typedef TBool (*TFixedOperation)(TAddress Data);

/*
  Input stream concept
*/
class IInputStream
{
  public:
    virtual TBool Read(TUnit * Unit) = 0;
};

/*
  Output stream concept
*/
class IOutputStream
{
  public:
    virtual TBool Write(TUnit Unit) = 0;
};

/*
  Address iterator

  Main use is avoid writing for's. For writing while's instead.

  Do implementation-specific. Then call GetNextAddr(&Addr)
  to get address. Until it fails.
*/
class TAddressIterator
{
  public:
    TBool Init(TAddress StartAddr, TAddress EndAddr);

    TBool GetAddr(TAddress * Address);
    TBool AdvanceAddr();

    TBool GetNextAddr(TAddress * Address);

  private:
    TAddress MaxAddr = 0;
    TAddress CurrentAddr = 1;

    TBool IsValidState();
};

/*
  2025-08-27
*/
