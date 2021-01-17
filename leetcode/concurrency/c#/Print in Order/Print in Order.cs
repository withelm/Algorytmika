public class Foo {

    
    public bool IsFirst;
    public bool IsSecond;
    
    public Foo() {
        IsFirst = false;
        IsSecond = false;
    }

    public void First(Action printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        IsFirst = true;
    }

    public void Second(Action printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        while(!IsFirst) {}
        printSecond();
        IsSecond = true;
    }

    public void Third(Action printThird) {
        

        // printThird() outputs "third". Do not change or remove this line.
        while(!IsSecond) {}
        printThird();
    }
}
