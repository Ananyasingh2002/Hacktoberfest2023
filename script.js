// Fetch data from db.json
fetch('db.json')
  .then(response => response.json())
  .then(data => {
    // Access the data and do something with it
    const employees = data.employees;
    employees.forEach(employee => {
      console.log(`ID: ${employee.id}, Name: ${employee.name}, Position: ${employee.position}`);
    });
  })
  .catch(error => console.error('Error fetching data:', error));
