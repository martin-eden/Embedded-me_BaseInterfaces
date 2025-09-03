// [me_BaseInterfaces] compilation check

/*
  Author: Martin Eden
  Last mod.: 2025-09-03
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

void PrintAddress(
  TAsciiz Annotation,
  TAddress Addr
)
{
  Console.Write(Annotation);
  Console.Print(Addr);
}

void PrintWrappings(
  TAsciiz Annotation,
  TAddressSegment AddrSeg
)
{
  Console.Write(Annotation);
  Console.Write(" ( ");
  PrintAddress("Addr", AddrSeg.Addr);
  PrintAddress("Size", AddrSeg.Size);
  Console.Write(")");
  Console.EndLine();
}

/*
  Test segment iterator
*/
void IteratorTest()
{
  TAddressSegment AddrSeg = { .Addr = TAddress_Max - 2, .Size = 3 };
  TAddrsegIterator Rator;
  TAddress Addr;

  Console.Print("( Address segment iterator test");
  Console.Indent();

  PrintWrappings("Test segment", AddrSeg);

  if (!Rator.Init(AddrSeg))
    Console.Print("Iterator init failed");

  while (Rator.GetNextAddr(&Addr))
  {
    Console.Write("Addr");
    Console.Print(Addr);
    Console.EndLine();
  }

  Console.Unindent();
  Console.Print(")");
}

void setup()
{
  Console.Init();

  Console.Print("( [me_BaseInterfaces] test");
  Console.Indent();

  CompilationTest();
  IteratorTest();

  Console.Unindent();
  Console.Print(") Done");
}

void loop()
{
}

/*
  2025 #
  2025-09-03
*/
