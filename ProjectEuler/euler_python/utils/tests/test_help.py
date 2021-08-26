import pytest

from utils.help import gcd, get_digits


@pytest.mark.parametrize(
    'a, b, expected', [
        (1, 1, 1),
        (2, 3, 1),
        (3, 4, 1),
        (4, 2, 2),
        (2, 4, 2),
    ]
)
def test_gcd(a, b, expected):
    assert gcd(a, b) == expected


@pytest.mark.parametrize(
    'a, expected', [
        (1, 1),
        (2, 1),
        (3, 1),
        (4, 1),
        (10, 2),
        (99, 2),
        (100, 3),
        (999, 3),
    ]
)
def test_get_digits(a, expected):
    assert get_digits(a) == expected
