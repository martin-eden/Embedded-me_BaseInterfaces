// Base interfaces for this framework

/*
  Author: Martin Eden
  Last mod.: 2025-09-03
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
  Void function call

  Three-address structure.

  We need first address to call something. We provide two extra
  addresses that can be used for input or output.
*/
typedef void (*TMethod)(TAddress Data, TAddress Instance);

/*
  Failable operation with two arguments

  Natural for most processing tasks.
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
  Address segment iterator

  Main use is avoid writing for's. For writing while's instead.

  Do implementation-specific Init(). Then call GetNextAddr(&Addr)
  to get address. Until it fails.
*/
class TAddrsegIterator
{
  public:
    // Setup iteration span
    TBool Init(TAddressSegment AddrSeg);

    // Get address and move cursor
    TBool GetNextAddr(TAddress * Address);

    // Get address
    TAddress GetAddr();
    // Move cursor
    void AdvanceAddr();
    // Check that iteration is complete
    TBool IsDone();

  private:
    TAddress MaxAddr;
    TAddress CurrentAddr;
    TBool IterationIsDone;
};

/*
  2025-08-27
  2025-08-28
  2025-09-03
*/
