# token_generator. Generate random strings.
#
# Copyright (C) 2021, Ty Gillespie. All rights reserved.
# MIT License.

import random

def generate(length = 8):
	"""Generates a token of the given length. The default is 8."""
	# Feel free to change this based on what you need your tokens to contain.
	SYMBOLS = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890"
	final = ""
	for i in range(length):
		final += SYMBOLS[random.randint(0, len(SYMBOLS) - 1)]
	return final
