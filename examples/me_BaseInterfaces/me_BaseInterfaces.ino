// [me_BaseInterfaces] compilation check

/*
  Author: Martin Eden
  Last mod.: 2025-08-27
*/

#include <me_BaseInterfaces.h>

#include <me_BaseTypes.h>
#include <me_Console.h>

void Func_Method(
  TAddress Data [[gnu::unused]],
  TAddress Instance [[gnu::unused]]
)
{
};

TBool Func_Operation(
  TAddress Data [[gnu::unused]],
  TAddress Instance [[gnu::unused]]
)
{
  return true;
};

TBool Func_FixedOperation(
  TAddress Data [[gnu::unused]]
)
{
  return true;
};

void CompilationTest()
{
  [[gnu::unused]] TMethod Method = Func_Method;
  [[gnu::unused]] TOperation Operation = Func_Operation;
  [[gnu::unused]] TFixedOperation FixedOperation = Func_FixedOperation;
}

void IteratorTest()
{
  TAddressSegment AddrSeg = { .Addr = TAddress_Max - 2, .Size = 3 };
  TAddressIterator Rator;
  TAddress Addr;

  Console.Print("( IteratorTest");

  if (!Rator.Init(AddrSeg))
    Console.Print("Iterator init failed");

  while (Rator.GetNextAddr(&Addr))
  {
    Console.Write("Addr");
    Console.Print(Addr);
    Console.EndLine();
  }

  Console.Print(") Done");
}

void setup()
{
  Console.Init();

  CompilationTest();
  IteratorTest();
}

void loop()
{
}

/*
  2025-08-27
*/
