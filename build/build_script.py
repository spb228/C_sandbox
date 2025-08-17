import os
import subprocess
import shutil
import sys

def run_command(command, cwd=None):
    print("\n" + "="*50)
    print(f"Running command: {command}")
    
    # Use capture_output=True to capture stdout and stderr
    # Use text=True to decode the output as strings
    result = subprocess.run(command, shell=True, cwd=cwd, capture_output=True, text=True)
    
    # if error, print it
    if result.returncode != 0:
        print("Command failed with return code:", result.returncode)
        print("--- Standard Output ---")
        print(result.stdout)  # Print stdout
        print("--- Standard Error ---")
        print(result.stderr)  # Print stderr, which often contains the error details
        print("="*50 + "\n")
        raise RuntimeError("Command failed")
    else:
        print("--- Standard Output ---")
        print(result.stdout)  # Print stdout

def main():
    project_root = os.path.abspath(os.path.dirname(__file__))
    build_dir = os.path.join(project_root, 'build')
    bin_dir = os.path.join(project_root, '../bin')

    # if build/build exists, delete it
    if os.path.exists(build_dir):
        shutil.rmtree(build_dir)

    # make build/build dir
    os.makedirs(build_dir, exist_ok=True)
    os.chdir(build_dir)

    if sys.platform == 'win32':
        # standard cmake and run commands
        cmake_config_command = 'cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug'
        cmake_build_command = 'mingw32-make'
        run_command_exe = 'c_sandbox.exe'
    else:
        # linux commands
        cmake_config_command = 'cmake .. -DCMAKE_BUILD_TYPE=Debug'
        cmake_build_command = 'make'
        run_command_exe = './c_sandbox'

    # execute build commands
    run_command(cmake_config_command)
    run_command(cmake_build_command)
    os.chdir(bin_dir)
    run_command(run_command_exe)

if __name__ == '__main__':
    main()