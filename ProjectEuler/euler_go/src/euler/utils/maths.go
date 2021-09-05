package utils

const (
    EPSILON = float64(.000_000_1)
)
type Vector2d struct {
    X, Y float64
}

type Vector3d struct {
    x, y, z float64
}


func (self *Vector2d) Cross(other *Vector2d) float64 {
    // 외적
    return self.X* other.Y - self.Y* other.X
}

func (self *Vector2d) Sub(other *Vector2d) *Vector2d {
    return &Vector2d{
        X: self.X - other.X,
        Y: self.Y - other.Y,
    }
}

func CCW2(a *Vector2d, b *Vector2d) float64 {
    // possitive : CCW
    // negative : CW
    // 0 : line
    return a.Cross(b)
}

func CCW3(c *Vector2d, a *Vector2d, b *Vector2d) float64 {
    // possitive : CCW
    // negative : CW
    // 0 : line
    a1 := a.Sub(c)
    b1 := b.Sub(c)
    return CCW2(a1, b1)
}