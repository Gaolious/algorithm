package utils

import "math/big"

const (
    EPSILON = float64(.000_000_1)
)
type Vector2d struct {
    X, Y float64
}

type Vector3d struct {
    x, y, z float64
}

type Fraction struct {
    //   b * root(c) + d
    //  -----------------
    //        e
    b, c, d, e *big.Int
}
func (f *Fraction) ContinuedFraction() (*big.Int, *Fraction){
    //      b * root(c) + d
    // 0 + -----------------
    //             e
    // [ sqrt(23)+4 ] / 7 => 1 + [ sqrt(23) - 3 ] / 7
    //
    // 23 >= (4 - (7*a))^2
    //    4.x >= 4 - 7*a  >= -4.x
    //    -8.x <= 7a <= 0.x
    // var a, b, c, d, e, e2 *big.Int
    // (d - f.e * a)^2 <= f.c
    // | (d - f.e * a) | <= sqrt(f.c)
    //
    // ( d - maxC ) / f.e
    //     var a, b, c, d, e, e2 int
    //     for a, d = 0, f.d ; ; a ++ {
    //         if (d - f.e * (a+1) ) * (d - f.e * (a+1) ) < f.c {
    //             continue
    //         } else {
    //             break
    //         }
    //     }
    return big.NewInt(1), f
}

//
//     //      b * root(c) + d-a*e
//     // a + -----------------
//     //             e
//
//     b = f.b
//     c = f.c
//     d = f.d - a * f.e
//     e = f.e
//
//     //                1
//     // a + -------------------------
//     //                e
//     //        -------------------
//     //        b * root(c) + d'
//
//     //                1
//     // a + --------------------------
//     //         e * [ b * root(c) - (d') ]
//     //        --------------------
//     //          b^2 * c - (d')^2
//     e2 = b*b*c - d*d
//     m := utils.GcdInt3(
//         utils.AbsInt(e*b),
//         utils.AbsInt(-e*d),
//         utils.AbsInt(e2),
//     )
//
//     return a, &fraction{
//         b : e * b / m,
//         c : c,
//         d: (-d) * e / m,
//         e: e2 / m,
//     }
// }

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

func IsPrime(n int64) bool {
    var i int64
    if n < 2 { return false }
    if n == 2 { return true }
    if n % 2 == 0 { return false }
    for i = 3 ; i*i <= n ; i ++ {
        if n % i == 0 { return false }
    }
    return true
}