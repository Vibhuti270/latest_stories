const express = require('express');
const app = express();

const https = require('https');
const cors = require('cors');
app.use(cors());
const fetchStory = async () => {
    return new Promise((resolve, reject) => {
      https.get('https://time.com', async (res) => {
        let data = '';
        res.on('data', (chunk) => data += chunk);
        res.on('end', () =>{
        try {
          let latestIndex = data.indexOf('latest-stories__item');
          if (latestIndex === -1) latestIndex = data.indexOf('LATEST STORIES');
  
          const latestHtml = data.slice(latestIndex);
          const aTagRegex = /<a\s+[\s\S]*?href="([^"]*)"[\s\S]*?>([\s\S]*?)<\/a>/gi;
          const stories = [];
  
          for (const match of latestHtml.matchAll(aTagRegex)) {
            const [, href, content] = match;
            const h3Match = content.match(/<h3[\s\S]*?>([\s\S]*?)<\/h3>/i);
            if (h3Match) {
              stories.push({
                title: h3Match[1].replace(/<[^>]+>/g, '').trim(),
                link: href.startsWith('https') ? href : `https://time.com${href}`
              });
              if (stories.length === 6) break;
            }
          }
          resolve(stories);
        } catch (err) {
          reject(err);
        }
        });
      }).on('error', reject);
    });
  };
        // 
app.get('/getTimeStories', async (req, res) => {
    try {
      const stories = await fetchStory();
      res.status(200).json(stories);
    } catch (err) {
      res.status(500).send(`Error: ${err.message}`);
    }
  });

  app.use((req, res) => {
    res.status(404).send('Error: Not Found');
  });
  
  app.listen(3000, () => {
    console.log('Server running on http://localhost:3000');
  });