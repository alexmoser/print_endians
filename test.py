#!/usr/bin/python3

import sys
import argparse
import subprocess
import json 


test_values = []

def fetch_tests(filename, verbose=True):
  """Loads the tests input/output pairs from a json file"""
  global test_values
  if verbose:
    print (f"Loaded test data from: {filename}")
  with open(filename) as f:
    test_values = json.load(f)['tests']

def parse_output(output):
  """parse the program output"""
  if 'INVALID' in output:
    return 'INVALID'
  
  if 'OUT OF RANGE' in output:
    return 'OUT OF RANGE'
  
  outs = output.split('\n')
  le = outs[1].split('\t')[1].strip()
  be = outs[2].split('\t')[1].strip()
  return f'{le}, {be}'

def assert_output(output, expected, verbose=True):
  """return True if output matches the expected value, False otherwise"""
  parsed_out = parse_output(output)
  if verbose:
    print(f"Got: {parsed_out}")
  if parsed_out == expected:
    return True
  else:
    return False

def run_test(verbose=True):
  """run the test util. Call after the tests have been fetched"""
  n = 1
  for t in test_values:
    process = subprocess.run(["./print_endian", t['input']], stdout=subprocess.PIPE, universal_newlines=True)
    output = process.stdout
    if verbose:
      print (f"Testing: '{t['input']}', Expected: {t['output']}")
      # print (output)
    if assert_output(output, t['output'], verbose):
      print (f"{n}/{len(test_values)}: passed")
    else:
      print (f"{n}/{len(test_values)}: failed")
    n += 1

  
if __name__ == "__main__":
  parser = argparse.ArgumentParser()
  parser.add_argument('-i', '--infile',
                      required=False,
                      type=str,
                      default="test_pairs.json", 
                      help="JSON input file that provides the in/out combinations to test" )
  parser.add_argument('-v', '--verbose',
                      required=False,
                      action="store_true",
                      help="Increase output verbosity")
  
  args = parser.parse_args(sys.argv[1:])
      
  if (args.infile.split('.')[-1] != 'json'):
    print ("Only .json files accepted as input!")
    sys.exit(2)

  fetch_tests(args.infile, verbose=args.verbose)
  run_test(verbose=args.verbose)