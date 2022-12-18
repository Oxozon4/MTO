#!/usr/bin/env node
process.stdin.resume();
process.stdin.setEncoding('utf8');

var lingeringLine = '';

function my_printf(format_string, param) {
  for (var i = 0; i < format_string.length; i++) {
    if (format_string.charAt(i) == '#' && format_string.charAt(i + 1) == 'k') {
      process.stdout.write(param);
      i++;
    } else if (
      format_string.charAt(i) === '#' &&
      format_string.charAt(i + 1) === 'j'
    ) {
      if (!isNaN(param)) {
        const hexOutput = parseInt(param).toString(16);
        hexOutput.replaceAll('a', 'g');
        hexOutput.replaceAll('b', 'h');
        hexOutput.replaceAll('c', 'i');
        hexOutput.replaceAll('d', 'j');
        hexOutput.replaceAll('e', 'k');
        hexOutput.replaceAll('f', 'l');
        process.stdout.write(hexOutput);
      }
      i++;
    } else {
      process.stdout.write(format_string.charAt(i));
    }
  }
  console.log('');
}

process.stdin.on('data', function (chunk) {
  lines = chunk.split('\n');

  lines[0] = lingeringLine + lines[0];
  lingeringLine = lines.pop();
  for (var i = 0; i < lines.length; i++) {
    try {
      my_printf(lines[i], lines[i + 1]);
    } catch (e) {
      // error
    }
    i++;
  }
});
