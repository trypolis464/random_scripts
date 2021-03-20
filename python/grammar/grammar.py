# grammar: grammar related functions.
#
# Copyright (C) 2021, Ty Gillespie. All rights reserved.
# MIT License.

def plural(number, option1, option2):
    r"""Returns the plural of the item if the number is more than 1, or less than -1.
    Takes the choices as parems, doesn't just add "s", so you can avoid "goose" becoming "gooses", for example.
    """
    if number == 1 or number == -1:
        return option1
    else:
        return option2
