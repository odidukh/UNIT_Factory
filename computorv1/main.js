const args = process.argv;

const main = (args) => {
	console.log(args);
}

if (require.main === module){
	main(process.argv.slice(2))
}
