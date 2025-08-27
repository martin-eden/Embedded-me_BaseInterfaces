// Address iterator implementation

/*
  Author: Martin Eden
  Last mod.: 2025-08-27
*/

#include <me_BaseInterfaces.h>

#include <me_BaseTypes.h>

/*
  Set iteration margins
*/
TBool TAddressIterator::Init(
  TAddress StartAddr,
  TAddress EndAddr
)
{
  this->CurrentAddr = StartAddr;
  this->MaxAddr = EndAddr;

  return IsValidState();
}

/*
  Check that iteration is not complete
*/
TBool TAddressIterator::IsValidState()
{
  return (CurrentAddr <= MaxAddr);
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
TBool TAddressIterator::AdvanceAddr()
{
  if (!IsValidState())
    return false;

  ++CurrentAddr;

  return true;
}

/*
  Get current address and advance
*/
TBool TAddressIterator::GetNextAddr(
  TAddress * Address
)
{
  return GetAddr(Address) && AdvanceAddr();
}

/*
  2025-08-27
*/
