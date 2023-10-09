import os
import urllib.error
from googlesearch import search  # You'll need to install the 'google' package for this
import config_params
from common_utils import menu_utils

VERSION = '1.0'

def load_google_hacks_list():
    # Load a list of Google hacks from a folder
    google_hacks = [f for f in os.listdir(config_params.GOOGLE_HACKS_FOLDER) if os.path.isfile(os.path.join(config_params.GOOGLE_HACKS_FOLDER, f))]
    return google_hacks

def get_strings(src_file):
    # Read and return the lines from a file as a list of strings
    try:
        with open(src_file, 'r') as file:
            return [line.strip() for line in file.readlines()]
    except FileNotFoundError:
        return []

def append_sitename(strs, site):
    # Add a site name to strings and count the number of Google search results
    google_hacks = []
    for x in strs:
        google_hack = f"{x} site:{site}"
        nres = results_in_google(google_hack)
        print(f"[+] {nres} results in: {google_hack}")
        if nres > 0:
            google_hacks.append(google_hack)
    return google_hacks

def save_output(strs):
    # Print the results
    res = "\n".join(strs)
    print(res)

def from_site(site_name, google_hack):
    # Create and save a list of Google dorks for a given site
    source_file = os.path.join(config_params.GOOGLE_HACKS_FOLDER, google_hack)
    menu_utils.header(source_file)

    if not os.path.isfile(source_file):
        menu_utils.error('Could not find source file!')
        return

    strs = get_strings(source_file)
    if not strs:
        menu_utils.error("Can't get data from source file!")
        return

    if site_name:
        strs = append_sitename(strs, site_name)

    save_output(strs)

def results_in_google(query):
    # Return the number of results found in Google using the given query
    counter = 0
    try:
        for j in search(query, tld="com", num=1, stop=1, pause=2):
            counter += 1
    except urllib.error.HTTPError as e:
        menu_utils.error(e)

    return counter

# Main entry point
if __name__ == "__main__":
    # You can add your code here to specify site_name and google_hack and call the necessary functions.
    pass
