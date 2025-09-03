// Address iterator implementation

/*
  Author: Martin Eden
  Last mod.: 2025-09-03
*/

#include <me_BaseInterfaces.h>

#include <me_BaseTypes.h>

#include <me_AddrsegTools.h>

/*
  We must handle case CurrentAddr == MaxAddr == 0xFFFF.
  We should do one iteration for that and stop after.
*/

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

  CurrentAddr = 0;
  MaxAddr = 0;
  IterationIsDone = true;

  if (!me_AddrsegTools::IsValid(AddrSeg))
    return false;

  CurrentAddr = AddrSeg.Addr;
  MaxAddr = AddrSeg.Addr + (AddrSeg.Size - 1);
  IterationIsDone = false;

  return true;
}

/*
  Return "iteration is done" flag
*/
TBool TAddressIterator::IsDone()
{
  return IterationIsDone;
}

/*
  Get current address
*/
TAddress TAddressIterator::GetAddr()
{
  return CurrentAddr;
}

/*
  Move to next address
*/
void TAddressIterator::AdvanceAddr()
{
  if (CurrentAddr == MaxAddr)
  {
    IterationIsDone = true;

    return;
  }

  CurrentAddr = CurrentAddr + 1;
}

/*
  Get current address and advance
*/
TBool TAddressIterator::GetNextAddr(
  TAddress * Address
)
{
  *Address = GetAddr();

  if (IsDone())
    return false;

  AdvanceAddr();

  return true;
}

/*
  2025-08-27
  2025-08-28
  2025-09-03
*/
