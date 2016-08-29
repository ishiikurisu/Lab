package cupcake;

public class Cupcake
{
    private String name;

    public Cupcake(String name)
    {
        this.name = name;
    }

    public String sayHi()
    {
        return "Hello from " + name + ", the cupcake!";
    }
}
