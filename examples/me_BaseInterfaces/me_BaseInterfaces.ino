// [me_BaseInterfaces] compilation check

/*
  Author: Martin Eden
  Last mod.: 2025-08-27
*/

#include <me_BaseInterfaces.h>

#include <me_BaseTypes.h>
#include <me_Console.h>

void CompilationTest()
{
}

void IteratorTest()
{
  TAddressIterator Rator;
  TAddress Addr;


  Console.Print("( IteratorTest");

  Rator.Init(1, 0);

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
