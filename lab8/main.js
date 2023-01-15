#!/usr/bin/env node
process.stdin.resume();
process.stdin.setEncoding('utf8');

var lingeringLine = '';

const getSubstringBetween = (str, part1, part2) => {
  const startIndex = str.indexOf(part1) + part1.length;
  const endIndex = str.indexOf(part2, startIndex);
  const stringBetween = str.substring(startIndex, endIndex);
  if (!isNaN(stringBetween) && Number.isInteger(Number(stringBetween))) {
    return parseInt(stringBetween);
  }
  return null;
};

function my_printf(format_string, param) {
  for (var i = 0; i < format_string.length; i++) {
    if (format_string.charAt(i) == '#' && format_string.charAt(i + 1) == 'k') {
      process.stdout.write(param);
      i++;
    } else if (
      format_string.charAt(i) === '#' &&
      format_string.charAt(i + 1) === '.'
    ) {
      if (!format_string.includes('x')) {
        process.stdout.write(param);
        i++;
        continue;
      }
      // #.5x 1
      // oooo1
      const precisionNumber = getSubstringBetween(format_string, '#.', '');
      if (!isNaN(param) && Number.isInteger(Number(param))) {
        const hexOutput = parseInt(param).toString(16);
        hexOutput.replace(/a/gi, 'g');
        hexOutput.replace(/b/gi, 'h');
        hexOutput.replace(/c/gi, 'i');
        hexOutput.replace(/d/gi, 'j');
        hexOutput.replace(/e/gi, 'k');
        hexOutput.replace(/f/gi, 'l');
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
