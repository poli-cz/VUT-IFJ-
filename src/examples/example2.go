// Program 2: Vypocet faktorialu (rekurzivne)
package main

func factorial(n int) (int) {
  dec_n := n - 1
  if n < 2 {
    return 1
  } else {
    a := 2
    tmp := 0
    tmp = factorial(a)




    return n * tmp
  }
}

func main() {
  print("Zadejte cislo pro vypocet faktorialu: ")
  a := 0
  err := 0
  a, err = inputi()
  if err == 0 {
    if a < 0 {
      print("Faktorial nejde spocitat!", "\n")
    } else {
      vysl := 0
      vysl = factorial(a)
      print("Vysledek je ", vysl, "\n")
    }
  } else {
    print("Chyba pri nacitani celeho cisla!\n")
  }
}



func tricker(n int)(string){

  n := "kobliha"



  return n
}
