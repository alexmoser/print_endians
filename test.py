import subprocess
import json 


test_values = []

def fetch_tests(filename):
  global test_values
  with open(filename) as f:
    test_values = json.load(f)['tests']

def parse_output(output):
  if 'INVALID' in output:
    return 'INVALID'
  
  if 'OUT OF RANGE' in output:
    return 'OUT OF RANGE'
  
  outs = output.split('\n')
  le = outs[1].split('\t')[1].strip()
  be = outs[2].split('\t')[1].strip()
  return f'{le}, {be}'

def assert_output(output, expected, verbose=True):
  parsed_out = parse_output(output)
  if verbose:
    print(f"Got: {parsed_out}")
  if parsed_out == expected:
    return True
  else:
    return False

def run_test(verbose=True):
  for t in test_values:
    process = subprocess.run(["./print_endian", t['input']], stdout=subprocess.PIPE, universal_newlines=True)
    output = process.stdout
    if verbose:
      print (f"Testing: '{t['input']}', Expected: {t['output']}")
      # print (output)
    if assert_output(output, t['output'], verbose):
      print ("passed")
    else:
      print ("failed")

  
if __name__ == "__main__":
  fetch_tests('test_pairs.json')
  run_test()