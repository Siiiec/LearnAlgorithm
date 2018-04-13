from decimal import Decimal, ROUND_HALF_UP

c = float(input())

print(Decimal(9 / 5 * c + 32).quantize(Decimal('0.01'), rounding=ROUND_HALF_UP))