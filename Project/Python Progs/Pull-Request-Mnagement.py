import datetime

class PullRequest:
    def __init__(self, name, domain, language):
        self.name = name
        self.domain = domain
        self.language = language
        self.date = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")

if __name__ == "__main__":
    pull_requests = []

    while True:
        name = input("Enter the name of the contributor: ")
        domain = input("Enter the domain of the project: ")
        language = input("Enter the programming language used: ")

        pull_request = PullRequest(name, domain, language)
        pull_requests.append(pull_request)

        print("Pull request added successfully.")

        add_another = input("Do you want to add another pull request? (y/n): ").lower()
        if add_another != 'y':
            break

    print("\nPull Requests:\n")
    for pr in pull_requests:
        print("Name:", pr.name)
        print("Domain:", pr.domain)
        print("Language:", pr.language)
        print("Date:", pr.date)
        print()
