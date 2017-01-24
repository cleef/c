
import math
import sys

""" cash * [(1+rate)^year - 1)]/rate """
def annuity_fv(rate, year, cash):
    return cash * ( math.pow(1+rate, year) - 1 )/ rate

def annuity_fv_divide(rate, year, fv):
    return 1.0 * fv * rate / ( math.pow(1+rate, year) -1 )

""" cash * [(1+rate) - (1+rate)^-year)]/rate """
def annuity_pv(rate, year, cash):
    return cash * ( 1 + rate - math.pow(1+rate, -1 * year) )/ rate

def annuity_test():
    cash = annuity_fv(0.08, 40, 10000);
    print cash
    cash = annuity_fv_divide(0.08, 25, 500000);
    print cash

    cash = annuity_pv(0.05, 15, 1000);
    print cash

annuity_test()
