class Animal
{
    public virtual void Move()
    {
        Console.WriteLine("Move!");
    }
}

class bird:Animal
{
    public override void Move()
    {
        Console.WriteLine("Fly!");
    }
}