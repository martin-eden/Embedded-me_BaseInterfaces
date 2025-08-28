// Address iterator implementation

/*
  Author: Martin Eden
  Last mod.: 2025-08-28
*/

#include <me_BaseInterfaces.h>

#include <me_BaseTypes.h>

#include <me_MemorySegment.h>

/*
  We must handle case CurrentAddr == MaxAddr == 0xFFFF.
  We should do one iteration for that and stop after.
*/

/*
  Check that iteration is not complete
*/
TBool TAddressIterator::IsValidState()
{
  return (CurrentAddr <= MaxAddr);
}

/*
  Create invalid state
*/
void TAddressIterator::Invalidate()
{
  CurrentAddr = 1;
  MaxAddr = 0;
}

/*
  Set iteration margins
*/
TBool TAddressIterator::Init(
  TAddressSegment AddrSeg
)
{
  /*
    Implementation relies on external segment validity check.

    So later we can do "Addr + (Size - 1)" without checking
    for overflows and underflows.
  */

  Invalidate();

  if (!me_MemorySegment::IsValid(AddrSeg))
    return false;

  this->CurrentAddr = AddrSeg.Addr;
  this->MaxAddr = AddrSeg.Addr + (AddrSeg.Size - 1);

  return IsValidState();
}

/*
  Get current address
*/
TBool TAddressIterator::GetAddr(
  TAddress * Address
)
{
  if (!IsValidState())
    return false;

  *Address = CurrentAddr;

  return true;
}

/*
  Move to next address
*/
void TAddressIterator::AdvanceAddr()
{
  if (!IsValidState())
    return;

  if (CurrentAddr == TAddress_Max)
  {
    Invalidate();

    return;
  }

  ++CurrentAddr;
}

/*
  Get current address and advance
*/
TBool TAddressIterator::GetNextAddr(
  TAddress * Address
)
{
  TBool Result;

  Result = GetAddr(Address);

  AdvanceAddr();

  return Result;
}

/*
  2025-08-27
  2025-08-28
*/
